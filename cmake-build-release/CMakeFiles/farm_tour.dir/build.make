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
include CMakeFiles/farm_tour.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/farm_tour.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/farm_tour.dir/flags.make

CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o: CMakeFiles/farm_tour.dir/flags.make
CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o: ../src/mid_level/farm_tour.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o -c /mnt/d/Mirror/algorithms/src/mid_level/farm_tour.cpp

CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Mirror/algorithms/src/mid_level/farm_tour.cpp > CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.i

CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Mirror/algorithms/src/mid_level/farm_tour.cpp -o CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.s

CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o.requires:

.PHONY : CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o.requires

CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o.provides: CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o.requires
	$(MAKE) -f CMakeFiles/farm_tour.dir/build.make CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o.provides.build
.PHONY : CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o.provides

CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o.provides.build: CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o


# Object files for target farm_tour
farm_tour_OBJECTS = \
"CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o"

# External object files for target farm_tour
farm_tour_EXTERNAL_OBJECTS =

farm_tour: CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o
farm_tour: CMakeFiles/farm_tour.dir/build.make
farm_tour: CMakeFiles/farm_tour.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable farm_tour"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/farm_tour.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/farm_tour.dir/build: farm_tour

.PHONY : CMakeFiles/farm_tour.dir/build

CMakeFiles/farm_tour.dir/requires: CMakeFiles/farm_tour.dir/src/mid_level/farm_tour.cpp.o.requires

.PHONY : CMakeFiles/farm_tour.dir/requires

CMakeFiles/farm_tour.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/farm_tour.dir/cmake_clean.cmake
.PHONY : CMakeFiles/farm_tour.dir/clean

CMakeFiles/farm_tour.dir/depend:
	cd /mnt/d/Mirror/algorithms/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms/cmake-build-release /mnt/d/Mirror/algorithms/cmake-build-release /mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles/farm_tour.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/farm_tour.dir/depend

