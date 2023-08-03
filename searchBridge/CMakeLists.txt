cmake_minimum_required(VERSION 3.26)
project(searchBridge)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(searchBridge
        DirectedGraph.cpp
        DirectedGraph.h
        Exeptions.h
        Func.cpp
        Graph.h
        Header.h
        main.cpp
        UndirectedGraph.cpp
        UndirectedGraph.h)
