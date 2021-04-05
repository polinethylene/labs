#add_subdirectory(/usr/src/gtest [binary_dir])
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(Tests test.c ../functions.c ../poly.c)
target_link_libraries(Tests)
#gtest_main
#add_executable(/usr/include/limits.h [binary_dir])
#add_subdirectory(../ctest-master [binary_dir])