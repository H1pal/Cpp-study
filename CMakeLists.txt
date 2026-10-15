cmake_minimum_required(VERSION 4.2)
project(c__test)

set(CMAKE_CXX_STANDARD 20)

add_executable(c__test main.cpp)
add_executable(study_vector study/vector.cpp)
add_executable(study01 study/01_HelloWorld/main.cpp)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/my/*.cpp")
add_executable(my ${MY_SOURCES})
target_include_directories(my PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/my")

add_subdirectory(solve)
