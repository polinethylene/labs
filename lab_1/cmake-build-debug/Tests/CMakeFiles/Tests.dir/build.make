# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/whitesnake/CLionProjects/lab_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug

# Include any dependencies generated for this target.
include Tests/CMakeFiles/Tests.dir/depend.make

# Include the progress variables for this target.
include Tests/CMakeFiles/Tests.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeFiles/Tests.dir/flags.make

Tests/CMakeFiles/Tests.dir/test.c.o: Tests/CMakeFiles/Tests.dir/flags.make
Tests/CMakeFiles/Tests.dir/test.c.o: ../Tests/test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Tests/CMakeFiles/Tests.dir/test.c.o"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tests.dir/test.c.o   -c /Users/whitesnake/CLionProjects/lab_1/Tests/test.c

Tests/CMakeFiles/Tests.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tests.dir/test.c.i"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/whitesnake/CLionProjects/lab_1/Tests/test.c > CMakeFiles/Tests.dir/test.c.i

Tests/CMakeFiles/Tests.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tests.dir/test.c.s"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/whitesnake/CLionProjects/lab_1/Tests/test.c -o CMakeFiles/Tests.dir/test.c.s

Tests/CMakeFiles/Tests.dir/__/functions.c.o: Tests/CMakeFiles/Tests.dir/flags.make
Tests/CMakeFiles/Tests.dir/__/functions.c.o: ../functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Tests/CMakeFiles/Tests.dir/__/functions.c.o"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tests.dir/__/functions.c.o   -c /Users/whitesnake/CLionProjects/lab_1/functions.c

Tests/CMakeFiles/Tests.dir/__/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tests.dir/__/functions.c.i"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/whitesnake/CLionProjects/lab_1/functions.c > CMakeFiles/Tests.dir/__/functions.c.i

Tests/CMakeFiles/Tests.dir/__/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tests.dir/__/functions.c.s"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/whitesnake/CLionProjects/lab_1/functions.c -o CMakeFiles/Tests.dir/__/functions.c.s

Tests/CMakeFiles/Tests.dir/__/poly.c.o: Tests/CMakeFiles/Tests.dir/flags.make
Tests/CMakeFiles/Tests.dir/__/poly.c.o: ../poly.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object Tests/CMakeFiles/Tests.dir/__/poly.c.o"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tests.dir/__/poly.c.o   -c /Users/whitesnake/CLionProjects/lab_1/poly.c

Tests/CMakeFiles/Tests.dir/__/poly.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tests.dir/__/poly.c.i"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/whitesnake/CLionProjects/lab_1/poly.c > CMakeFiles/Tests.dir/__/poly.c.i

Tests/CMakeFiles/Tests.dir/__/poly.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tests.dir/__/poly.c.s"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/whitesnake/CLionProjects/lab_1/poly.c -o CMakeFiles/Tests.dir/__/poly.c.s

# Object files for target Tests
Tests_OBJECTS = \
"CMakeFiles/Tests.dir/test.c.o" \
"CMakeFiles/Tests.dir/__/functions.c.o" \
"CMakeFiles/Tests.dir/__/poly.c.o"

# External object files for target Tests
Tests_EXTERNAL_OBJECTS =

Tests/Tests: Tests/CMakeFiles/Tests.dir/test.c.o
Tests/Tests: Tests/CMakeFiles/Tests.dir/__/functions.c.o
Tests/Tests: Tests/CMakeFiles/Tests.dir/__/poly.c.o
Tests/Tests: Tests/CMakeFiles/Tests.dir/build.make
Tests/Tests: Tests/CMakeFiles/Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Tests"
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeFiles/Tests.dir/build: Tests/Tests

.PHONY : Tests/CMakeFiles/Tests.dir/build

Tests/CMakeFiles/Tests.dir/clean:
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests && $(CMAKE_COMMAND) -P CMakeFiles/Tests.dir/cmake_clean.cmake
.PHONY : Tests/CMakeFiles/Tests.dir/clean

Tests/CMakeFiles/Tests.dir/depend:
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/whitesnake/CLionProjects/lab_1 /Users/whitesnake/CLionProjects/lab_1/Tests /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/Tests/CMakeFiles/Tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/CMakeFiles/Tests.dir/depend
