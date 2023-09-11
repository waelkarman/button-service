cmake_minimum_required(VERSION 3.15)

project(gpio-read-sysfs-service)
find_package(sysfsgpio)
find_package(cppzmq)
find_package(zmqpp)
find_package(zmq)

add_executable(gpio-read-sysfs-service zhelpers.hpp gpio-read-sysfs-service.cpp)

target_link_libraries(gpio-read-sysfs-service sysfsgpio cppzmq zmqpp zmq)

install(TARGETS gpio-read-sysfs-service DESTINATION bin)
