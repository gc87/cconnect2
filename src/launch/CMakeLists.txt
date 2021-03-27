set(src launch.cpp ../common/zmqclient.cpp ../common/cconnect2.pb.cc)
add_executable(launch ${src})
target_link_libraries(launch cppzmq protobuf)