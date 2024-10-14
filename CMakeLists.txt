cmake_minimum_required(VERSION 3.15)
project(Lec15)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(SOURCE_FILES main.cpp)
add_executable(Lec15 ${SOURCE_FILES})
