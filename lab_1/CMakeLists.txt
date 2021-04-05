cmake_minimum_required(VERSION 3.17)
project(lab_1)

set(CMAKE_C_STANDARD 11)

add_subdirectory(Tests)
add_executable(lab_1 main.c functions.c poly.c)
