# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /snap/cmake/1366/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1366/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/Documents/C++/cpu_emulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Documents/C++/cpu_emulator/build

# Include any dependencies generated for this target.
include libs/Stack/CMakeFiles/test_Stack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/Stack/CMakeFiles/test_Stack.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/Stack/CMakeFiles/test_Stack.dir/progress.make

# Include the compile flags for this target's objects.
include libs/Stack/CMakeFiles/test_Stack.dir/flags.make

libs/Stack/CMakeFiles/test_Stack.dir/test/test.cpp.o: libs/Stack/CMakeFiles/test_Stack.dir/flags.make
libs/Stack/CMakeFiles/test_Stack.dir/test/test.cpp.o: /home/user/Documents/C++/cpu_emulator/libs/Stack/test/test.cpp
libs/Stack/CMakeFiles/test_Stack.dir/test/test.cpp.o: libs/Stack/CMakeFiles/test_Stack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Documents/C++/cpu_emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/Stack/CMakeFiles/test_Stack.dir/test/test.cpp.o"
	cd /home/user/Documents/C++/cpu_emulator/build/libs/Stack && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/Stack/CMakeFiles/test_Stack.dir/test/test.cpp.o -MF CMakeFiles/test_Stack.dir/test/test.cpp.o.d -o CMakeFiles/test_Stack.dir/test/test.cpp.o -c /home/user/Documents/C++/cpu_emulator/libs/Stack/test/test.cpp

libs/Stack/CMakeFiles/test_Stack.dir/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_Stack.dir/test/test.cpp.i"
	cd /home/user/Documents/C++/cpu_emulator/build/libs/Stack && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/C++/cpu_emulator/libs/Stack/test/test.cpp > CMakeFiles/test_Stack.dir/test/test.cpp.i

libs/Stack/CMakeFiles/test_Stack.dir/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_Stack.dir/test/test.cpp.s"
	cd /home/user/Documents/C++/cpu_emulator/build/libs/Stack && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/C++/cpu_emulator/libs/Stack/test/test.cpp -o CMakeFiles/test_Stack.dir/test/test.cpp.s

# Object files for target test_Stack
test_Stack_OBJECTS = \
"CMakeFiles/test_Stack.dir/test/test.cpp.o"

# External object files for target test_Stack
test_Stack_EXTERNAL_OBJECTS =

libs/Stack/test_Stack: libs/Stack/CMakeFiles/test_Stack.dir/test/test.cpp.o
libs/Stack/test_Stack: libs/Stack/CMakeFiles/test_Stack.dir/build.make
libs/Stack/test_Stack: libs/Stack/libStack.a
libs/Stack/test_Stack: lib/libgtest_main.a
libs/Stack/test_Stack: lib/libgtest.a
libs/Stack/test_Stack: libs/Stack/CMakeFiles/test_Stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/user/Documents/C++/cpu_emulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_Stack"
	cd /home/user/Documents/C++/cpu_emulator/build/libs/Stack && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_Stack.dir/link.txt --verbose=$(VERBOSE)
	cd /home/user/Documents/C++/cpu_emulator/build/libs/Stack && /snap/cmake/1366/bin/cmake -D TEST_TARGET=test_Stack -D TEST_EXECUTABLE=/home/user/Documents/C++/cpu_emulator/build/libs/Stack/test_Stack -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/user/Documents/C++/cpu_emulator/build/libs/Stack -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test_Stack_TESTS -D CTEST_FILE=/home/user/Documents/C++/cpu_emulator/build/libs/Stack/test_Stack[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /snap/cmake/1366/share/cmake-3.28/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
libs/Stack/CMakeFiles/test_Stack.dir/build: libs/Stack/test_Stack
.PHONY : libs/Stack/CMakeFiles/test_Stack.dir/build

libs/Stack/CMakeFiles/test_Stack.dir/clean:
	cd /home/user/Documents/C++/cpu_emulator/build/libs/Stack && $(CMAKE_COMMAND) -P CMakeFiles/test_Stack.dir/cmake_clean.cmake
.PHONY : libs/Stack/CMakeFiles/test_Stack.dir/clean

libs/Stack/CMakeFiles/test_Stack.dir/depend:
	cd /home/user/Documents/C++/cpu_emulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Documents/C++/cpu_emulator /home/user/Documents/C++/cpu_emulator/libs/Stack /home/user/Documents/C++/cpu_emulator/build /home/user/Documents/C++/cpu_emulator/build/libs/Stack /home/user/Documents/C++/cpu_emulator/build/libs/Stack/CMakeFiles/test_Stack.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libs/Stack/CMakeFiles/test_Stack.dir/depend
