cmake_minimum_required(VERSION 3.21)
project(Stack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Stack
        Main.cpp
        Stack.h)
