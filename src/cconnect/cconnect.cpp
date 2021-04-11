#include "cconnect.h"
#include <boost/interprocess/sync/file_lock.hpp>
#include <boost/process.hpp>
#include <boost/process/env.hpp>
#include <iostream>
#include <zmq_addon.hpp>
#include "zmqserver.h"

using namespace std;
using namespace cconnect2;
using namespace boost::process;

int main(int argc, char *argv[]) {
  // TODO:添加文件锁，保证只有一个cconnect进程在运行
  // TODO:添加命令行解析

  string mainIPC("ipc://cconnect.ipc");
  cconnect::ZmqServer zmqServer(mainIPC);
  // TODO:设置lmdbwrap实例到server中
  zmqServer.ServerLoop();

  return 0;
}