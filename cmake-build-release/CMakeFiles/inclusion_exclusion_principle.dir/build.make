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
include CMakeFiles/inclusion_exclusion_principle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/inclusion_exclusion_principle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inclusion_exclusion_principle.dir/flags.make

CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o: CMakeFiles/inclusion_exclusion_principle.dir/flags.make
CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o: ../src/advanced/inclusion_exclusion_principle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o -c /mnt/d/Mirror/algorithms/src/advanced/inclusion_exclusion_principle.cpp

CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Mirror/algorithms/src/advanced/inclusion_exclusion_principle.cpp > CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.i

CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Mirror/algorithms/src/advanced/inclusion_exclusion_principle.cpp -o CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.s

CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o.requires:

.PHONY : CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o.requires

CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o.provides: CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o.requires
	$(MAKE) -f CMakeFiles/inclusion_exclusion_principle.dir/build.make CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o.provides.build
.PHONY : CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o.provides

CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o.provides.build: CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o


# Object files for target inclusion_exclusion_principle
inclusion_exclusion_principle_OBJECTS = \
"CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o"

# External object files for target inclusion_exclusion_principle
inclusion_exclusion_principle_EXTERNAL_OBJECTS =

inclusion_exclusion_principle: CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o
inclusion_exclusion_principle: CMakeFiles/inclusion_exclusion_principle.dir/build.make
inclusion_exclusion_principle: CMakeFiles/inclusion_exclusion_principle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable inclusion_exclusion_principle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inclusion_exclusion_principle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inclusion_exclusion_principle.dir/build: inclusion_exclusion_principle

.PHONY : CMakeFiles/inclusion_exclusion_principle.dir/build

CMakeFiles/inclusion_exclusion_principle.dir/requires: CMakeFiles/inclusion_exclusion_principle.dir/src/advanced/inclusion_exclusion_principle.cpp.o.requires

.PHONY : CMakeFiles/inclusion_exclusion_principle.dir/requires

CMakeFiles/inclusion_exclusion_principle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inclusion_exclusion_principle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inclusion_exclusion_principle.dir/clean

CMakeFiles/inclusion_exclusion_principle.dir/depend:
	cd /mnt/d/Mirror/algorithms/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms/cmake-build-release /mnt/d/Mirror/algorithms/cmake-build-release /mnt/d/Mirror/algorithms/cmake-build-release/CMakeFiles/inclusion_exclusion_principle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inclusion_exclusion_principle.dir/depend

