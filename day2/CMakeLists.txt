cmake_minimum_required(VERSION 3.10)
project(aoc_day2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(day2 main.cpp)
target_compile_options(day2 PRIVATE -Wall -Wextra -Wpedantic)