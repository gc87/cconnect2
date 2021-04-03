set(src cconnect.cpp zmqserver.cpp ../common/cconnect2.pb.cc lmdbwrap.cpp)
add_executable(cconnect ${src})
target_link_libraries(cconnect cppzmq boost_system boost_filesystem protobuf lmdb)