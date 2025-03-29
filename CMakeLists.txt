cmake_minimum_required(VERSION 3.30)
project(Heap)

set(CMAKE_CXX_STANDARD 20)

add_executable(Heap main.cpp
        heap.h
        heap.cpp
        utils.cpp
        utils.h
        graph.cpp
        graph.h
        vector.cpp
        vector.h
        pair.cpp
        pair.h
)
