cmake_minimum_required(VERSION 3.10)
project(multi-server-pthread)


add_executable(multi-server-pthread multi-server-pthread.cpp)
target_link_libraries(multi-server-pthread pthread)
