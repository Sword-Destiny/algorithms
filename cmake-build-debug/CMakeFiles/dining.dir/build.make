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
CMAKE_BINARY_DIR = /mnt/d/Mirror/algorithms/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dining.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dining.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dining.dir/flags.make

CMakeFiles/dining.dir/src/mid_level/dining.cpp.o: CMakeFiles/dining.dir/flags.make
CMakeFiles/dining.dir/src/mid_level/dining.cpp.o: ../src/mid_level/dining.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dining.dir/src/mid_level/dining.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dining.dir/src/mid_level/dining.cpp.o -c /mnt/d/Mirror/algorithms/src/mid_level/dining.cpp

CMakeFiles/dining.dir/src/mid_level/dining.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dining.dir/src/mid_level/dining.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Mirror/algorithms/src/mid_level/dining.cpp > CMakeFiles/dining.dir/src/mid_level/dining.cpp.i

CMakeFiles/dining.dir/src/mid_level/dining.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dining.dir/src/mid_level/dining.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Mirror/algorithms/src/mid_level/dining.cpp -o CMakeFiles/dining.dir/src/mid_level/dining.cpp.s

CMakeFiles/dining.dir/src/mid_level/dining.cpp.o.requires:

.PHONY : CMakeFiles/dining.dir/src/mid_level/dining.cpp.o.requires

CMakeFiles/dining.dir/src/mid_level/dining.cpp.o.provides: CMakeFiles/dining.dir/src/mid_level/dining.cpp.o.requires
	$(MAKE) -f CMakeFiles/dining.dir/build.make CMakeFiles/dining.dir/src/mid_level/dining.cpp.o.provides.build
.PHONY : CMakeFiles/dining.dir/src/mid_level/dining.cpp.o.provides

CMakeFiles/dining.dir/src/mid_level/dining.cpp.o.provides.build: CMakeFiles/dining.dir/src/mid_level/dining.cpp.o


# Object files for target dining
dining_OBJECTS = \
"CMakeFiles/dining.dir/src/mid_level/dining.cpp.o"

# External object files for target dining
dining_EXTERNAL_OBJECTS =

dining: CMakeFiles/dining.dir/src/mid_level/dining.cpp.o
dining: CMakeFiles/dining.dir/build.make
dining: CMakeFiles/dining.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dining"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dining.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dining.dir/build: dining

.PHONY : CMakeFiles/dining.dir/build

CMakeFiles/dining.dir/requires: CMakeFiles/dining.dir/src/mid_level/dining.cpp.o.requires

.PHONY : CMakeFiles/dining.dir/requires

CMakeFiles/dining.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dining.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dining.dir/clean

CMakeFiles/dining.dir/depend:
	cd /mnt/d/Mirror/algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms/cmake-build-debug /mnt/d/Mirror/algorithms/cmake-build-debug /mnt/d/Mirror/algorithms/cmake-build-debug/CMakeFiles/dining.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dining.dir/depend

