# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake/cmake-3.19.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake/cmake-3.19.1-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.N5Ecl1aLuq

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.N5Ecl1aLuq/cmake-build-debug

# Include any dependencies generated for this target.
include Tests/[binary_dir]/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include Tests/[binary_dir]/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/[binary_dir]/CMakeFiles/gtest_main.dir/flags.make

Tests/[binary_dir]/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: Tests/[binary_dir]/CMakeFiles/gtest_main.dir/flags.make
Tests/[binary_dir]/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: /usr/src/gtest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.N5Ecl1aLuq/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/[binary_dir]/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /tmp/tmp.N5Ecl1aLuq/cmake-build-debug/Tests/[binary_dir] && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /usr/src/gtest/src/gtest_main.cc

Tests/[binary_dir]/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /tmp/tmp.N5Ecl1aLuq/cmake-build-debug/Tests/[binary_dir] && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/src/gtest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

Tests/[binary_dir]/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /tmp/tmp.N5Ecl1aLuq/cmake-build-debug/Tests/[binary_dir] && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/src/gtest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

Tests/[binary_dir]/libgtest_main.a: Tests/[binary_dir]/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
Tests/[binary_dir]/libgtest_main.a: Tests/[binary_dir]/CMakeFiles/gtest_main.dir/build.make
Tests/[binary_dir]/libgtest_main.a: Tests/[binary_dir]/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.N5Ecl1aLuq/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /tmp/tmp.N5Ecl1aLuq/cmake-build-debug/Tests/[binary_dir] && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /tmp/tmp.N5Ecl1aLuq/cmake-build-debug/Tests/[binary_dir] && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/[binary_dir]/CMakeFiles/gtest_main.dir/build: Tests/[binary_dir]/libgtest_main.a

.PHONY : Tests/[binary_dir]/CMakeFiles/gtest_main.dir/build

Tests/[binary_dir]/CMakeFiles/gtest_main.dir/clean:
	cd /tmp/tmp.N5Ecl1aLuq/cmake-build-debug/Tests/[binary_dir] && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : Tests/[binary_dir]/CMakeFiles/gtest_main.dir/clean

Tests/[binary_dir]/CMakeFiles/gtest_main.dir/depend:
	cd /tmp/tmp.N5Ecl1aLuq/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.N5Ecl1aLuq /usr/src/gtest /tmp/tmp.N5Ecl1aLuq/cmake-build-debug /tmp/tmp.N5Ecl1aLuq/cmake-build-debug/Tests/[binary_dir] /tmp/tmp.N5Ecl1aLuq/cmake-build-debug/Tests/[binary_dir]/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/[binary_dir]/CMakeFiles/gtest_main.dir/depend
