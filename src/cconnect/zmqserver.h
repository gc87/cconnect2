#ifndef ZMQ_SERVER_H
#define ZMQ_SERVER_H

#include <zmq.hpp>
#include <zmq_addon.hpp>
#include "../common/cconnect2.pb.h"
#include "lmdbwrap.h"

namespace cconnect2 {
  namespace cconnect {
    class ZmqServer {
     private:
      std::string ipc;
      zmq::context_t zmqContext;
      zmq::socket_t zmqSock;
      std::map<std::string, std::set<std::string>> channels;
      std::mutex pubSocksMutex;
      std::map<std::string, std::shared_ptr<zmq::socket_t>> publishSocks;
      bool threadRunning;
      bool serverRunning;
      LmdbWarp lmdbWarp;

     public:
      ZmqServer(const std::string ipc);
      void SetLmdbWrap(LmdbWarp &lmdbWrap);
      void PublishMessage();
      void ServerLoop();
      void ServerStop();

      ~ZmqServer() = default;

     private:
      std::string connectHandle(const Connect &connect,
                                const std::string &name,
                                const int &pid);
      std::string pingHandle(Ping &ping);
      std::string subscribeHandle(Sub &subscribe);
      std::string unsubscribeHandle(Unsub &unsubscribe);
      std::string methodHandle(Method &method);
      std::string parseDBP(const std::string &str);
      void mainSockHandle();
      void addPublishSock();
      void deletePublishSock();
      std::string generatePubIPCString(const std::string &name,
                                       const int &pid) const;
    };
  }  // namespace cconnect
}  // namespace cconnect2

#endif