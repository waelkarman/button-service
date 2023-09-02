cmake_minimum_required(VERSION 3.15)

project(zmqread)
find_package(sysfsgpio)

add_executable(zmqread zmqread.cpp)

target_link_libraries(zmqread sysfsgpio)

install(TARGETS zmqread DESTINATION bin)
