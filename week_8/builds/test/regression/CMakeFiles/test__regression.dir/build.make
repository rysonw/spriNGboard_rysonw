# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ryson/spriNGboard_rysonw/week_8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ryson/spriNGboard_rysonw/week_8/builds

# Include any dependencies generated for this target.
include test/regression/CMakeFiles/test__regression.dir/depend.make

# Include the progress variables for this target.
include test/regression/CMakeFiles/test__regression.dir/progress.make

# Include the compile flags for this target's objects.
include test/regression/CMakeFiles/test__regression.dir/flags.make

test/regression/CMakeFiles/test__regression.dir/test__regression.cc.o: test/regression/CMakeFiles/test__regression.dir/flags.make
test/regression/CMakeFiles/test__regression.dir/test__regression.cc.o: ../test/regression/test__regression.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ryson/spriNGboard_rysonw/week_8/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/regression/CMakeFiles/test__regression.dir/test__regression.cc.o"
	cd /home/ryson/spriNGboard_rysonw/week_8/builds/test/regression && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test__regression.dir/test__regression.cc.o -c /home/ryson/spriNGboard_rysonw/week_8/test/regression/test__regression.cc

test/regression/CMakeFiles/test__regression.dir/test__regression.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test__regression.dir/test__regression.cc.i"
	cd /home/ryson/spriNGboard_rysonw/week_8/builds/test/regression && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ryson/spriNGboard_rysonw/week_8/test/regression/test__regression.cc > CMakeFiles/test__regression.dir/test__regression.cc.i

test/regression/CMakeFiles/test__regression.dir/test__regression.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test__regression.dir/test__regression.cc.s"
	cd /home/ryson/spriNGboard_rysonw/week_8/builds/test/regression && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ryson/spriNGboard_rysonw/week_8/test/regression/test__regression.cc -o CMakeFiles/test__regression.dir/test__regression.cc.s

# Object files for target test__regression
test__regression_OBJECTS = \
"CMakeFiles/test__regression.dir/test__regression.cc.o"

# External object files for target test__regression
test__regression_EXTERNAL_OBJECTS =

test/regression/test__regression: test/regression/CMakeFiles/test__regression.dir/test__regression.cc.o
test/regression/test__regression: test/regression/CMakeFiles/test__regression.dir/build.make
test/regression/test__regression: ../catch_install/lib64/libCatch2Main.a
test/regression/test__regression: ../catch_install/lib64/libCatch2.a
test/regression/test__regression: test/regression/CMakeFiles/test__regression.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ryson/spriNGboard_rysonw/week_8/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test__regression"
	cd /home/ryson/spriNGboard_rysonw/week_8/builds/test/regression && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test__regression.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/regression/CMakeFiles/test__regression.dir/build: test/regression/test__regression

.PHONY : test/regression/CMakeFiles/test__regression.dir/build

test/regression/CMakeFiles/test__regression.dir/clean:
	cd /home/ryson/spriNGboard_rysonw/week_8/builds/test/regression && $(CMAKE_COMMAND) -P CMakeFiles/test__regression.dir/cmake_clean.cmake
.PHONY : test/regression/CMakeFiles/test__regression.dir/clean

test/regression/CMakeFiles/test__regression.dir/depend:
	cd /home/ryson/spriNGboard_rysonw/week_8/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ryson/spriNGboard_rysonw/week_8 /home/ryson/spriNGboard_rysonw/week_8/test/regression /home/ryson/spriNGboard_rysonw/week_8/builds /home/ryson/spriNGboard_rysonw/week_8/builds/test/regression /home/ryson/spriNGboard_rysonw/week_8/builds/test/regression/CMakeFiles/test__regression.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/regression/CMakeFiles/test__regression.dir/depend

