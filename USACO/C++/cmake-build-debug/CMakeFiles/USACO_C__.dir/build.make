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
CMAKE_SOURCE_DIR = /Users/kush/CLionProjects/USACO_C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kush/CLionProjects/USACO_C++/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/USACO_C__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/USACO_C__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/USACO_C__.dir/flags.make

CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.o: CMakeFiles/USACO_C__.dir/flags.make
CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.o: ../av_botz_maximum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kush/CLionProjects/USACO_C++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.o -c /Users/kush/CLionProjects/USACO_C++/av_botz_maximum.cpp

CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kush/CLionProjects/USACO_C++/av_botz_maximum.cpp > CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.i

CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kush/CLionProjects/USACO_C++/av_botz_maximum.cpp -o CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.s

# Object files for target USACO_C__
USACO_C___OBJECTS = \
"CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.o"

# External object files for target USACO_C__
USACO_C___EXTERNAL_OBJECTS =

USACO_C__: CMakeFiles/USACO_C__.dir/av_botz_maximum.cpp.o
USACO_C__: CMakeFiles/USACO_C__.dir/build.make
USACO_C__: CMakeFiles/USACO_C__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kush/CLionProjects/USACO_C++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable USACO_C__"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/USACO_C__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/USACO_C__.dir/build: USACO_C__

.PHONY : CMakeFiles/USACO_C__.dir/build

CMakeFiles/USACO_C__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/USACO_C__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/USACO_C__.dir/clean

CMakeFiles/USACO_C__.dir/depend:
	cd /Users/kush/CLionProjects/USACO_C++/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kush/CLionProjects/USACO_C++ /Users/kush/CLionProjects/USACO_C++ /Users/kush/CLionProjects/USACO_C++/cmake-build-debug /Users/kush/CLionProjects/USACO_C++/cmake-build-debug /Users/kush/CLionProjects/USACO_C++/cmake-build-debug/CMakeFiles/USACO_C__.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/USACO_C__.dir/depend

