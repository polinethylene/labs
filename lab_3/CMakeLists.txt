cmake_minimum_required(VERSION 3.17)
project(lab_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_3 main.cpp b_tree.h Stack.h Complex.h functions.h functions.cpp Person.h)
add_subdirectory(Set)
add_subdirectory(Tests)