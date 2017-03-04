cmake_minimum_required(VERSION 3.6)
project(term2_notes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES scratchpad/hello_world.cpp scratchpad/hello_world.h)
add_executable(term2_notes ${SOURCE_FILES})