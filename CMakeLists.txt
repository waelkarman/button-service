cmake_minimum_required(VERSION 3.15)

project(read)
find_package(sysfsgpio)

add_executable(read read.cpp)

target_link_libraries(read sysfsgpio)

#install(TARGETS read DESTINATION bin)
