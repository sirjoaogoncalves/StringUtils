cmake_minimum_required(VERSION 3.10)
project(StringUtils)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(test_string_utils test/main.cpp)