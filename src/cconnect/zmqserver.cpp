#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <mutex>
#include <thread>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include "../common/cconnect2.pb.h"
#include "lmdbwrap.h"
#include "zmqserver.h"

using namespace std;

namespace cconnect2 {
namespace cconnect {

ZmqServer::ZmqServer(const std::string ipc)
    : ipc(ipc) {
    zmqSock = zmq::socket_t(zmqContext, zmq::socket_type::rep);
    zmqSock.bind(ipc);
}

void ZmqServer::SetLmdbWrap(LmdbWarp &lmdbWrap) {
    lmdbWarp = lmdbWarp;
}

void ZmqServer::mainSockHandle() {
    std::thread t([ this ]() {
        while (threadRunning) {
            {
                // std::lock_guard<std::mutex> lg(messageListMutex);
                // if (!messageList.empty()) {
                //     auto item = messageList.cbegin();
                //     messageList.pop_front();
                // }
            }
        }
    });

    t.detach();
}

string ZmqServer::generatePubIPCString(const std::string &name, const int &pid) const {
    return "ipc://cconnect-" + name + "-" + to_string(pid) + ".ipc";
}

string ZmqServer::connectHandle(const Connect &connect, const string &name, const int &pid) {
    shared_ptr<zmq::socket_t> sock   = make_shared<zmq::socket_t>(zmqContext, zmq::socket_type::pub);
    string                    pubIPC = generatePubIPCString(name, pid);
    sock->bind(pubIPC);

    {
        std::lock_guard<std::mutex> lg(pubSocksMutex);

        if (publishSocks.find(pubIPC) == publishSocks.end()) {
            publishSocks.insert(std::make_pair(pubIPC, sock));
        }
    }

    // TODO: 创建返回结果
    return string("");
}

string ZmqServer::pingHandle(Ping &ping) {
    Pong pong;
    pong.set_id(ping.id());

    Base newBase;
    newBase.set_msg(Msg::PONG);
    newBase.mutable_object()->PackFrom(pong);

    string serializeStr;
    newBase.SerializeToString(&serializeStr);

    return serializeStr;
}

string ZmqServer::parseDBP(const string &str) {
    Base base;
    if (!base.ParseFromString(str)) {
        return string("");
    }

    if (base.object().Is<Connect>()) {
        Connect connect;
        base.object().UnpackTo(&connect);
        return connectHandle(connect, base.name(), base.pid());
    }

    if (base.object().Is<Ping>()) {
        Ping ping;
        base.object().UnpackTo(&ping);
        return pingHandle(ping);
    }

    return string("");
}

void ZmqServer::ServerLoop() {
    threadRunning = true;
    serverRunning = true;

    mainSockHandle();

    while (serverRunning) {
        zmq::message_t msg;
        auto           res = zmqSock.recv(msg, zmq::recv_flags::none);

        if (res) {
            const string str       = msg.to_string();
            const string returnStr = parseDBP(str);

            // {
            //     std::lock_guard<std::mutex> lg(messageListMutex);
            // }

            zmq::message_t result(returnStr.c_str(), returnStr.length());
            zmqSock.send(result, zmq::send_flags::none);
        }
    }
}

void ZmqServer::ServerStop() {
    threadRunning = false;
    serverRunning = false;
}

} // namespace cconnect
} // namespace cconnect2