#ifndef ZMQ_SERVER_H
#define ZMQ_SERVER_H

#include "../common/cconnect2.pb.h"
#include "lmdbwrap.h"

using namespace std;

namespace cconnect2 {
namespace cconnect {
class ZmqServer {
private:
    string                                 ipc;
    zmq::context_t                         zmqContext;
    zmq::socket_t                          zmqSock;
    map<string, set<string>>               channels;
    mutex                                  pubSocksMutex;
    map<string, shared_ptr<zmq::socket_t>> publishSocks;
    bool                                   threadRunning;
    bool                                   serverRunning;
    LmdbWarp                               lmdbWarp;

public:
    ZmqServer(const string ipc);
    void SetLmdbWrap(LmdbWarp &lmdbWrap);
    void PublishMessage();
    void ServerLoop();
    void ServerStop();

    ~ZmqServer() = default;

private:
    string connectHandle(const Connect &connect, const string &name, const int &pid);
    string pingHandle(Ping &ping);
    string subscribeHandle(Sub &subscribe);
    string unsubscribeHandle(Unsub &unsubscribe);
    string methodHandle(Method &method);
    string parseDBP(const string &str);
    void   mainSockHandle();
    void   addPublishSock();
    void   deletePublishSock();
    string generatePubIPCString(const string &name, const int &pid) const;
};
} // namespace cconnect
} // namespace cconnect2

#endif