# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/Mirror/algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Mirror/algorithms/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/min_cost_flow.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/min_cost_flow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/min_cost_flow.dir/flags.make

CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o: CMakeFiles/min_cost_flow.dir/flags.make
CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o: ../src/mid_level/min_cost_flow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o -c /mnt/d/Mirror/algorithms/src/mid_level/min_cost_flow.cpp

CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Mirror/algorithms/src/mid_level/min_cost_flow.cpp > CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.i

CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Mirror/algorithms/src/mid_level/min_cost_flow.cpp -o CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.s

CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o.requires:

.PHONY : CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o.requires

CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o.provides: CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o.requires
	$(MAKE) -f CMakeFiles/min_cost_flow.dir/build.make CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o.provides.build
.PHONY : CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o.provides

CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o.provides.build: CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o


# Object files for target min_cost_flow
min_cost_flow_OBJECTS = \
"CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o"

# External object files for target min_cost_flow
min_cost_flow_EXTERNAL_OBJECTS =

min_cost_flow: CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o
min_cost_flow: CMakeFiles/min_cost_flow.dir/build.make
min_cost_flow: CMakeFiles/min_cost_flow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable min_cost_flow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/min_cost_flow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/min_cost_flow.dir/build: min_cost_flow

.PHONY : CMakeFiles/min_cost_flow.dir/build

CMakeFiles/min_cost_flow.dir/requires: CMakeFiles/min_cost_flow.dir/src/mid_level/min_cost_flow.cpp.o.requires

.PHONY : CMakeFiles/min_cost_flow.dir/requires

CMakeFiles/min_cost_flow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/min_cost_flow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/min_cost_flow.dir/clean

CMakeFiles/min_cost_flow.dir/depend:
	cd /mnt/d/Mirror/algorithms/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms/cmake-build-release /mnt/d/Mirror/algorithms/cmake-build-release /mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles/min_cost_flow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/min_cost_flow.dir/depend

