cmake_minimum_required(VERSION 3.17)
project(lab_2)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Tests)
add_subdirectory(Sequence)
add_executable(lab_2 main.cpp DynArray.h ArraySeq.h Sequence.h LinkedListSeq.h LinkList.h Matrix.h Complex.h)

target_compile_options(lab_2 PRIVATE -Wall -Wextra -pedantic)