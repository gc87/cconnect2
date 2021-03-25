set(src launch.cpp ../common/zmqclient.cpp ../common/dbp.pb.cc)
add_executable(launch ${src})
target_link_libraries(launch cppzmq protobuf)