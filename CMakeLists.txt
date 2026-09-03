cmake_minimum_required(VERSION 4.2)
project(c__test)

set(CMAKE_CXX_STANDARD 20)

add_executable(c__test main.cpp)
add_executable(judge ProgrammersOJ.cpp)
add_executable(study_vector study/vector.cpp)
add_executable(study01 study/01_HelloWorld/main.cpp
        study/01_HelloWorld/header1.h
        study/01_HelloWorld/header2.h)