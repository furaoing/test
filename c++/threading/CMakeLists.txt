cmake_minimum_required(VERSION 3.3)
project(threading)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread -std=c++11")
set(${SOURCE_FILES} roy_socket.cpp)
FIND_PACKAGE(Threads REQUIRED)
add_executable(roy_socket.exe ${SOURCE_FILES})
TARGET_LINK_LIBRARIES ( roy_socket.exe ${CMAKE_THREAD_LIBS_INIT} )