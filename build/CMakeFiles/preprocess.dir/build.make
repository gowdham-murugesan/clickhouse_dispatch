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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/build

# Utility rule file for preprocess.

# Include any custom commands dependencies for this target.
include CMakeFiles/preprocess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/preprocess.dir/progress.make

CMakeFiles/preprocess: /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/normalFunctions.cpp
CMakeFiles/preprocess: /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/normalMultiple.cpp
CMakeFiles/preprocess: /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/classMemberFunctions.cpp

/home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/classMemberFunctions.cpp: class
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating preprocessed output for classMemberFunctions.cpp"
	/usr/bin/clang++ -E -DENABLE_MULTITARGET_CODE=1 /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/classMemberFunctions.cpp -o /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/classMemberFunctions.cpp

/home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/normalFunctions.cpp: normal
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating preprocessed output for normalFunctions.cpp"
	/usr/bin/clang++ -E -DENABLE_MULTITARGET_CODE=1 /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/normalFunctions.cpp -o /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/normalFunctions.cpp

/home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/normalMultiple.cpp: multiple
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating preprocessed output for normalMultiple.cpp"
	/usr/bin/clang++ -E -DENABLE_MULTITARGET_CODE=1 /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/normalMultiple.cpp -o /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/normalMultiple.cpp

preprocess: CMakeFiles/preprocess
preprocess: /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/classMemberFunctions.cpp
preprocess: /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/normalFunctions.cpp
preprocess: /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/preprocessed_dump/normalMultiple.cpp
preprocess: CMakeFiles/preprocess.dir/build.make
.PHONY : preprocess

# Rule to build all files generated by this target.
CMakeFiles/preprocess.dir/build: preprocess
.PHONY : CMakeFiles/preprocess.dir/build

CMakeFiles/preprocess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/preprocess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/preprocess.dir/clean

CMakeFiles/preprocess.dir/depend:
	cd /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/build /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/build /home/gowdham-pt7685/Gowdham/Dispatch_clickhouse/build/CMakeFiles/preprocess.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/preprocess.dir/depend

