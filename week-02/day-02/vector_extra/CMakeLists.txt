cmake_minimum_required(VERSION 3.14)
project(vector_extra C)

set(CMAKE_C_STANDARD 99)

add_executable(vector_extra main.c vector.c vector.h)