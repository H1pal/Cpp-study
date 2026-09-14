cmake_minimum_required(VERSION 4.2)
project(c__test)

set(CMAKE_CXX_STANDARD 20)

add_executable(c__test main.cpp)
add_executable(study_vector study/vector.cpp)
add_executable(study01 study/01_HelloWorld/main.cpp)

add_subdirectory(solve)