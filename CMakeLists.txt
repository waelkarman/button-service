cmake_minimum_required(VERSION 3.15)

project(zmqread)
find_package(sysfsgpio)
find_package(cppzmq)
find_package(zmqpp)
find_package(zmq)

add_executable(zmqread zhelpers.hpp zmqread.cpp)

target_link_libraries(zmqread sysfsgpio cppzmq zmqpp zmq)

install(TARGETS zmqread DESTINATION bin)
