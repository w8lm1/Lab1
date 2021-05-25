cmake_minimum_required(VERSION 3.17)
project(progs C)

set(CMAKE_C_STANDARD 99)

add_executable(progs main.c Lin.c tests.c Linint.c lindo.c)