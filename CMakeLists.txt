cmake_minimum_required(VERSION 3.15)
project(networking_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(echo-server)
add_subdirectory(multi-server-fork)
add_subdirectory(multi-server-pthread)
add_subdirectory(multi-server-epoll)