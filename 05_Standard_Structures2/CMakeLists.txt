cmake_minimum_required(VERSION 3.21)
project(DDList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(List
        DLList.h
        Main.cpp)