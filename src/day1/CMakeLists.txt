cmake_minimum_required (VERSION 3.7.0)
set(EXEC day1)

project(${EXEC})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(${EXEC} main.cc)
add_subdirectory(../../lib/Catch2 ../../lib/Catch2/build)

target_include_directories(${EXEC} PRIVATE ../../include)
target_link_libraries(${EXEC} PRIVATE Catch2::Catch2WithMain)
