set(src cconnect.cpp zmqserver.cpp ../common/dbp.pb.cc)
add_executable(cconnect ${src})
target_link_libraries(cconnect cppzmq boost_system boost_filesystem protobuf)