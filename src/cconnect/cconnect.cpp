#include <iostream>
#include <zmq_addon.hpp>
#include <boost/process.hpp>
#include "zmqserver.h"
#include "cconnect.h"

using namespace cconnect2;
using namespace boost::process;
int main(int argc, char *argv[]) {
    std::string         mainIPC("ipc://cconnect.ipc");
    cconnect::ZmqServer zmqServer(mainIPC);
    zmqServer.ServerLoop();
    return 0;
}