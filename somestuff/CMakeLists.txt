cmake_minimum_required(VERSION 3.15)
project(somestuff)

set(CMAKE_CXX_STANDARD 14)

add_executable(somestuff main.cpp cube.cpp cube.h Exceptions.h algo.cpp algo.h)