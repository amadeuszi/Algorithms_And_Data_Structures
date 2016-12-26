cmake_minimum_required(VERSION 3.6)
project(Graphs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    Graph.cpp
    Graph.h
    Graphs.cpp)

add_executable(Graphs ${SOURCE_FILES})