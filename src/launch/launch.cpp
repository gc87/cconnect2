#include <iostream>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include "../common/cconnect2.pb.h"
#include "../common/zmqclient.h"

using namespace std;
using namespace cconnect2;

int main(int argc, char *argv[]) {
    std::string    mainIPC("ipc://cconnect.ipc");
    zmq::context_t ctx;
    zmq::socket_t  sock(ctx, zmq::socket_type::req);
    sock.connect(mainIPC);

    while (true) {
        Base base;
        base.set_msg(Msg::PING);

        Ping ping;
        ping.set_id("10001");

        base.mutable_object()->PackFrom(ping);
        string serializeStr;
        base.SerializeToString(&serializeStr);

        zmq::message_t result(serializeStr.c_str(), serializeStr.length());
        sock.send(result, zmq::send_flags::dontwait);

        // sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
        zmq::message_t m;
        sock.recv(m, zmq::recv_flags::none);

        Base         newBase;
        Pong         pong;
        const string str = m.to_string();
        newBase.ParseFromString(str);

        if (newBase.object().Is<Pong>()) {
            if (newBase.object().UnpackTo(&pong)) {
                std::cout << pong.id() << std::endl;
            }
        }

        // std::string str = m.to_string();
        std::cout << newBase.msg() << std::endl;
    }

    return 0;
}