#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <mutex>
#include <thread>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include "../common/dbp.pb.h"
#include "zmqserver.h"

using namespace std;
namespace cconnect2 {
namespace cconnect {

ZmqServer::ZmqServer(const std::string ipc)
    : ipc(ipc) {
    zmqSock = zmq::socket_t(zmqContext, zmq::socket_type::rep);
    zmqSock.bind(ipc);
}

void ZmqServer::mainSockHandle() {
    std::thread t([ this ]() {
        while (threadRunning) {
            {
                std::lock_guard<std::mutex> lg(messageListMutex);
                if (!messageList.empty()) {
                    auto item = messageList.cbegin();
                    messageList.pop_front();
                }
            }
        }
    });

    t.detach();
}

string ZmqServer::connectHandle(dbp::Base &base) {
    return string("");
}

string ZmqServer::pingHandle(dbp::Base &base) {
    dbp::Pong pong;
    pong.set_id("10000");

    dbp::Base newBase;
    newBase.set_msg(dbp::Msg::PONG);
    newBase.mutable_object()->PackFrom(pong);

    string serializeStr;
    newBase.SerializeToString(&serializeStr);

    return serializeStr;
}

string ZmqServer::parseDBP(const string &str) {
    dbp::Base base;
    if (!base.ParseFromString(str)) {
        return string("");
    }

    switch (base.msg()) {
        case dbp::Msg::CONNECT:
            return connectHandle(base);
            break;
        case dbp::Msg::PING:
            return pingHandle(base);
            break;

        default:
            break;
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