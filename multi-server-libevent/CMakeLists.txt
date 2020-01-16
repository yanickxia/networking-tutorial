cmake_minimum_required(VERSION 3.10)
project(multi-server-libevent)

add_executable(multi-server-libevent multi-server-libevent.c)
target_link_libraries(multi-server-libevent event)
