cmake_minimum_required(VERSION 4.2)
project(c__test)

set(CMAKE_CXX_STANDARD 20)

add_executable(c__test main.cpp
        ProgrammersOJ.cpp
        study/vector.cpp)

add_executable(vector study/vector.cpp)