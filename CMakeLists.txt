cmake_minimum_required(VERSION 3.7)
project(Vincent)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp proto.cpp proto.h area.cpp area.h)
add_executable(Vincent ${SOURCE_FILES})