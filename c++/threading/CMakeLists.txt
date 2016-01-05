cmake_minimum_required(VERSION 3.3)
project(threading)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread -std=c++11")
set(SOURCE_FILES main.cpp test_threading_socket.cpp test_threading_socket.h)
FIND_PACKAGE(Threads REQUIRED)
add_executable(threading ${SOURCE_FILES})
TARGET_LINK_LIBRARIES ( threading ${CMAKE_THREAD_LIBS_INIT} )