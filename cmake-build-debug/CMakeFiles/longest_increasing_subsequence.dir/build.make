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
include CMakeFiles/longest_increasing_subsequence.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/longest_increasing_subsequence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/longest_increasing_subsequence.dir/flags.make

CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o: CMakeFiles/longest_increasing_subsequence.dir/flags.make
CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o: ../src/base/longest_increasing_subsequence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o -c /mnt/d/Mirror/algorithms/src/base/longest_increasing_subsequence.cpp

CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Mirror/algorithms/src/base/longest_increasing_subsequence.cpp > CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.i

CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Mirror/algorithms/src/base/longest_increasing_subsequence.cpp -o CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.s

CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o.requires:

.PHONY : CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o.requires

CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o.provides: CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o.requires
	$(MAKE) -f CMakeFiles/longest_increasing_subsequence.dir/build.make CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o.provides.build
.PHONY : CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o.provides

CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o.provides.build: CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o


# Object files for target longest_increasing_subsequence
longest_increasing_subsequence_OBJECTS = \
"CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o"

# External object files for target longest_increasing_subsequence
longest_increasing_subsequence_EXTERNAL_OBJECTS =

longest_increasing_subsequence: CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o
longest_increasing_subsequence: CMakeFiles/longest_increasing_subsequence.dir/build.make
longest_increasing_subsequence: CMakeFiles/longest_increasing_subsequence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Mirror/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable longest_increasing_subsequence"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/longest_increasing_subsequence.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/longest_increasing_subsequence.dir/build: longest_increasing_subsequence

.PHONY : CMakeFiles/longest_increasing_subsequence.dir/build

CMakeFiles/longest_increasing_subsequence.dir/requires: CMakeFiles/longest_increasing_subsequence.dir/src/base/longest_increasing_subsequence.cpp.o.requires

.PHONY : CMakeFiles/longest_increasing_subsequence.dir/requires

CMakeFiles/longest_increasing_subsequence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/longest_increasing_subsequence.dir/cmake_clean.cmake
.PHONY : CMakeFiles/longest_increasing_subsequence.dir/clean

CMakeFiles/longest_increasing_subsequence.dir/depend:
	cd /mnt/d/Mirror/algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms /mnt/d/Mirror/algorithms/cmake-build-debug /mnt/d/Mirror/algorithms/cmake-build-debug /mnt/d/Mirror/algorithms/cmake-build-debug/CMakeFiles/longest_increasing_subsequence.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/longest_increasing_subsequence.dir/depend

