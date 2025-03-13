# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/paubover/Escritorio/2dCuatri/Practicas_mh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paubover/Escritorio/2dCuatri/Practicas_mh

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/paubover/Escritorio/2dCuatri/Practicas_mh/CMakeFiles /home/paubover/Escritorio/2dCuatri/Practicas_mh//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/paubover/Escritorio/2dCuatri/Practicas_mh/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

src/brutesearch.o: src/brutesearch.cpp.o
.PHONY : src/brutesearch.o

# target to build an object file
src/brutesearch.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/brutesearch.cpp.o
.PHONY : src/brutesearch.cpp.o

src/brutesearch.i: src/brutesearch.cpp.i
.PHONY : src/brutesearch.i

# target to preprocess a source file
src/brutesearch.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/brutesearch.cpp.i
.PHONY : src/brutesearch.cpp.i

src/brutesearch.s: src/brutesearch.cpp.s
.PHONY : src/brutesearch.s

# target to generate assembly for a file
src/brutesearch.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/brutesearch.cpp.s
.PHONY : src/brutesearch.cpp.s

src/greedy.o: src/greedy.cpp.o
.PHONY : src/greedy.o

# target to build an object file
src/greedy.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/greedy.cpp.o
.PHONY : src/greedy.cpp.o

src/greedy.i: src/greedy.cpp.i
.PHONY : src/greedy.i

# target to preprocess a source file
src/greedy.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/greedy.cpp.i
.PHONY : src/greedy.cpp.i

src/greedy.s: src/greedy.cpp.s
.PHONY : src/greedy.s

# target to generate assembly for a file
src/greedy.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/greedy.cpp.s
.PHONY : src/greedy.cpp.s

src/pincrem.o: src/pincrem.cpp.o
.PHONY : src/pincrem.o

# target to build an object file
src/pincrem.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/pincrem.cpp.o
.PHONY : src/pincrem.cpp.o

src/pincrem.i: src/pincrem.cpp.i
.PHONY : src/pincrem.i

# target to preprocess a source file
src/pincrem.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/pincrem.cpp.i
.PHONY : src/pincrem.cpp.i

src/pincrem.s: src/pincrem.cpp.s
.PHONY : src/pincrem.s

# target to generate assembly for a file
src/pincrem.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/pincrem.cpp.s
.PHONY : src/pincrem.cpp.s

src/randomsearch.o: src/randomsearch.cpp.o
.PHONY : src/randomsearch.o

# target to build an object file
src/randomsearch.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/randomsearch.cpp.o
.PHONY : src/randomsearch.cpp.o

src/randomsearch.i: src/randomsearch.cpp.i
.PHONY : src/randomsearch.i

# target to preprocess a source file
src/randomsearch.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/randomsearch.cpp.i
.PHONY : src/randomsearch.cpp.i

src/randomsearch.s: src/randomsearch.cpp.s
.PHONY : src/randomsearch.s

# target to generate assembly for a file
src/randomsearch.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/randomsearch.cpp.s
.PHONY : src/randomsearch.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/brutesearch.o"
	@echo "... src/brutesearch.i"
	@echo "... src/brutesearch.s"
	@echo "... src/greedy.o"
	@echo "... src/greedy.i"
	@echo "... src/greedy.s"
	@echo "... src/pincrem.o"
	@echo "... src/pincrem.i"
	@echo "... src/pincrem.s"
	@echo "... src/randomsearch.o"
	@echo "... src/randomsearch.i"
	@echo "... src/randomsearch.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

