cmake_minimum_required(VERSION 3.17)
project(grid_map C)

set(CMAKE_C_STANDARD 99)

add_executable(grid_map grid-map/main.c common/fixed.h)