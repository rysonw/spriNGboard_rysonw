cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

## This is not recommended:
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-O2")

project(Trivia VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSION OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
  Catch2 3 REQUIRED
  PATHS ./catch_install
  NO_DEFAULT_PATH
)

#add_subdirectory(src)

enable_testing()
add_subdirectory(test)

add_test(
    NAME test__exercise_01_cvs
    COMMAND $<TARGET_FILE:test__exercise_01_cvs>
)

