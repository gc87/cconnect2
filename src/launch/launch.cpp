#include <iostream>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include "../common/dbp.pb.h"
#include "../common/zmqclient.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::string    mainIPC("ipc://cconnect.ipc");
    zmq::context_t ctx;
    zmq::socket_t  sock(ctx, zmq::socket_type::req);
    sock.connect(mainIPC);

    while (true) {
        dbp::Base base;
        base.set_msg(dbp::Msg::PING);

        dbp::Ping ping;
        ping.set_id("10001");

        base.mutable_object()->PackFrom(ping);
        string serializeStr;
        base.SerializeToString(&serializeStr);

        zmq::message_t result(serializeStr.c_str(), serializeStr.length());
        sock.send(result, zmq::send_flags::dontwait);

        // sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
        zmq::message_t m;
        sock.recv(m, zmq::recv_flags::none);

        dbp::Base    newBase;
        dbp::Pong    pong;
        const string str = m.to_string();
        newBase.ParseFromString(str);

        // std::string str = m.to_string();
        std::cout << newBase.msg() << std::endl;
    }

    return 0;
}