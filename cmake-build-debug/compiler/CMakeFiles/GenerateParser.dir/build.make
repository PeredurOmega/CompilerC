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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/pauls/CLionProjects/CompilerC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/pauls/CLionProjects/CompilerC/cmake-build-debug

# Utility rule file for GenerateParser.

# Include the progress variables for this target.
include compiler/CMakeFiles/GenerateParser.dir/progress.make

compiler/CMakeFiles/GenerateParser: ../compiler/generated/ifccBaseListener.cpp
compiler/CMakeFiles/GenerateParser: ../compiler/generated/ifccBaseVisitor.cpp
compiler/CMakeFiles/GenerateParser: ../compiler/generated/ifccLexer.cpp
compiler/CMakeFiles/GenerateParser: ../compiler/generated/ifccListener.cpp
compiler/CMakeFiles/GenerateParser: ../compiler/generated/ifccParser.cpp
compiler/CMakeFiles/GenerateParser: ../compiler/generated/ifccVisitor.cpp


../compiler/generated/ifccBaseListener.cpp: ../compiler/ifcc.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/pauls/CLionProjects/CompilerC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../compiler/generated/ifccBaseListener.cpp, ../../compiler/generated/ifccBaseVisitor.cpp, ../../compiler/generated/ifccLexer.cpp, ../../compiler/generated/ifccListener.cpp, ../../compiler/generated/ifccParser.cpp, ../../compiler/generated/ifccVisitor.cpp"
	/usr/local/bin/cmake -E make_directory /mnt/c/Users/pauls/CLionProjects/CompilerC/compiler/generated/

../compiler/generated/ifccBaseVisitor.cpp: ../compiler/generated/ifccBaseListener.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../compiler/generated/ifccBaseVisitor.cpp

../compiler/generated/ifccLexer.cpp: ../compiler/generated/ifccBaseListener.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../compiler/generated/ifccLexer.cpp

../compiler/generated/ifccListener.cpp: ../compiler/generated/ifccBaseListener.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../compiler/generated/ifccListener.cpp

../compiler/generated/ifccParser.cpp: ../compiler/generated/ifccBaseListener.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../compiler/generated/ifccParser.cpp

../compiler/generated/ifccVisitor.cpp: ../compiler/generated/ifccBaseListener.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../compiler/generated/ifccVisitor.cpp

GenerateParser: compiler/CMakeFiles/GenerateParser
GenerateParser: ../compiler/generated/ifccBaseListener.cpp
GenerateParser: ../compiler/generated/ifccBaseVisitor.cpp
GenerateParser: ../compiler/generated/ifccLexer.cpp
GenerateParser: ../compiler/generated/ifccListener.cpp
GenerateParser: ../compiler/generated/ifccParser.cpp
GenerateParser: ../compiler/generated/ifccVisitor.cpp
GenerateParser: compiler/CMakeFiles/GenerateParser.dir/build.make

.PHONY : GenerateParser

# Rule to build all files generated by this target.
compiler/CMakeFiles/GenerateParser.dir/build: GenerateParser

.PHONY : compiler/CMakeFiles/GenerateParser.dir/build

compiler/CMakeFiles/GenerateParser.dir/clean:
	cd /mnt/c/Users/pauls/CLionProjects/CompilerC/cmake-build-debug/compiler && $(CMAKE_COMMAND) -P CMakeFiles/GenerateParser.dir/cmake_clean.cmake
.PHONY : compiler/CMakeFiles/GenerateParser.dir/clean

compiler/CMakeFiles/GenerateParser.dir/depend:
	cd /mnt/c/Users/pauls/CLionProjects/CompilerC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/pauls/CLionProjects/CompilerC /mnt/c/Users/pauls/CLionProjects/CompilerC/compiler /mnt/c/Users/pauls/CLionProjects/CompilerC/cmake-build-debug /mnt/c/Users/pauls/CLionProjects/CompilerC/cmake-build-debug/compiler /mnt/c/Users/pauls/CLionProjects/CompilerC/cmake-build-debug/compiler/CMakeFiles/GenerateParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : compiler/CMakeFiles/GenerateParser.dir/depend

