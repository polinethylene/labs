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
include CMakeFiles/lab_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_1.dir/flags.make

CMakeFiles/lab_1.dir/main.c.o: CMakeFiles/lab_1.dir/flags.make
CMakeFiles/lab_1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab_1.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab_1.dir/main.c.o   -c /Users/whitesnake/CLionProjects/lab_1/main.c

CMakeFiles/lab_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab_1.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/whitesnake/CLionProjects/lab_1/main.c > CMakeFiles/lab_1.dir/main.c.i

CMakeFiles/lab_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab_1.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/whitesnake/CLionProjects/lab_1/main.c -o CMakeFiles/lab_1.dir/main.c.s

CMakeFiles/lab_1.dir/functions.c.o: CMakeFiles/lab_1.dir/flags.make
CMakeFiles/lab_1.dir/functions.c.o: ../functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab_1.dir/functions.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab_1.dir/functions.c.o   -c /Users/whitesnake/CLionProjects/lab_1/functions.c

CMakeFiles/lab_1.dir/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab_1.dir/functions.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/whitesnake/CLionProjects/lab_1/functions.c > CMakeFiles/lab_1.dir/functions.c.i

CMakeFiles/lab_1.dir/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab_1.dir/functions.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/whitesnake/CLionProjects/lab_1/functions.c -o CMakeFiles/lab_1.dir/functions.c.s

CMakeFiles/lab_1.dir/poly.c.o: CMakeFiles/lab_1.dir/flags.make
CMakeFiles/lab_1.dir/poly.c.o: ../poly.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab_1.dir/poly.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab_1.dir/poly.c.o   -c /Users/whitesnake/CLionProjects/lab_1/poly.c

CMakeFiles/lab_1.dir/poly.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab_1.dir/poly.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/whitesnake/CLionProjects/lab_1/poly.c > CMakeFiles/lab_1.dir/poly.c.i

CMakeFiles/lab_1.dir/poly.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab_1.dir/poly.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/whitesnake/CLionProjects/lab_1/poly.c -o CMakeFiles/lab_1.dir/poly.c.s

# Object files for target lab_1
lab_1_OBJECTS = \
"CMakeFiles/lab_1.dir/main.c.o" \
"CMakeFiles/lab_1.dir/functions.c.o" \
"CMakeFiles/lab_1.dir/poly.c.o"

# External object files for target lab_1
lab_1_EXTERNAL_OBJECTS =

lab_1: CMakeFiles/lab_1.dir/main.c.o
lab_1: CMakeFiles/lab_1.dir/functions.c.o
lab_1: CMakeFiles/lab_1.dir/poly.c.o
lab_1: CMakeFiles/lab_1.dir/build.make
lab_1: CMakeFiles/lab_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lab_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_1.dir/build: lab_1

.PHONY : CMakeFiles/lab_1.dir/build

CMakeFiles/lab_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_1.dir/clean

CMakeFiles/lab_1.dir/depend:
	cd /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/whitesnake/CLionProjects/lab_1 /Users/whitesnake/CLionProjects/lab_1 /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug /Users/whitesnake/CLionProjects/lab_1/cmake-build-debug/CMakeFiles/lab_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_1.dir/depend
