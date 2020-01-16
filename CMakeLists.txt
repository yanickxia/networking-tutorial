cmake_minimum_required(VERSION 3.10)
project(networking_tutorial)

set(CMAKE_CXX_STANDARD 14)


include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_subdirectory(echo-server)
add_subdirectory(multi-server-fork)
add_subdirectory(multi-server-pthread)
add_subdirectory(multi-server-epoll)
add_subdirectory(multi-server-libevent)