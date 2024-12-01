cmake_minimum_required(VERSION 3.22)
project(advent_of_code_2024 C CXX)
set(CMAKE_CXX_STANDARD 20)

# Halt on the first error
set(CMAKE_POLICY_CONFIGURE_EARLY_OUT_FOR_FATAL_ERRORS ON)

add_subdirectory(chapter01/problem_01)

set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/include")
set(LIBS_PATH "${CMAKE_SOURCE_DIR}/libs")

#include_directories(${PROJECT_SOURCE_DIR}/inc)
#add_executable(kalk main.cc)

#enable_testing()
#add_subdirectory(unittests)
