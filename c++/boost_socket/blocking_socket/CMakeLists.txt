cmake_minimum_required(VERSION 3.3)
project(boost)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_filesystem -lboost_system -pthread -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(boost ${SOURCE_FILES})