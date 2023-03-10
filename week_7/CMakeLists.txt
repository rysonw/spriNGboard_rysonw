cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

## This is not recommended:
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-O2")

project(Trivia VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSION OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

