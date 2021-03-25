#ifndef ZMQ_SERVER_H
#define ZMQ_SERVER_H

#include "../common/dbp.pb.h"

namespace cconnect2 {
namespace cconnect {
class ZmqServer {
private:
    std::string                          ipc;
    zmq::context_t                       zmqContext;
    zmq::socket_t                        zmqSock;
    std::map<std::string, zmq::socket_t> publishSocks;
    std::mutex                           messageListMutex;
    std::list<std::string>               messageList;
    bool                                 threadRunning;
    bool                                 serverRunning;

public:
    ZmqServer(const std::string ipc);
    void PublishMessage();
    void ServerLoop();
    void ServerStop();

    ~ZmqServer() = default;

private:
    std::string connectHandle(dbp::Base &base);
    std::string pingHandle(dbp::Base &base);
    std::string subscribeHandle(dbp::Base &base);
    std::string unSubscribeHandle(dbp::Base &base);
    std::string methodHandle(dbp::Base &base);
    std::string parseDBP(const std::string &str);
    void        mainSockHandle();
    void        addPublishSock();
    void        deletePublishSock();
};
} // namespace cconnect
} // namespace cconnect2

#endif