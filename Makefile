# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Applications/CMake.app/Contents/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CMake.app/Contents/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/CMakeFiles" "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named GameUtility

# Build rule for target.
GameUtility: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 GameUtility
.PHONY : GameUtility

# fast build rule for target.
GameUtility/fast:
	$(MAKE) -f CMakeFiles/GameUtility.dir/build.make CMakeFiles/GameUtility.dir/build
.PHONY : GameUtility/fast

#=============================================================================
# Target rules for targets named GameServer

# Build rule for target.
GameServer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 GameServer
.PHONY : GameServer

# fast build rule for target.
GameServer/fast:
	$(MAKE) -f CMakeFiles/GameServer.dir/build.make CMakeFiles/GameServer.dir/build
.PHONY : GameServer/fast

#=============================================================================
# Target rules for targets named GameClient

# Build rule for target.
GameClient: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 GameClient
.PHONY : GameClient

# fast build rule for target.
GameClient/fast:
	$(MAKE) -f CMakeFiles/GameClient.dir/build.make CMakeFiles/GameClient.dir/build
.PHONY : GameClient/fast

GameClient.o: GameClient.c.o

.PHONY : GameClient.o

# target to build an object file
GameClient.c.o:
	$(MAKE) -f CMakeFiles/GameClient.dir/build.make CMakeFiles/GameClient.dir/GameClient.c.o
.PHONY : GameClient.c.o

GameClient.i: GameClient.c.i

.PHONY : GameClient.i

# target to preprocess a source file
GameClient.c.i:
	$(MAKE) -f CMakeFiles/GameClient.dir/build.make CMakeFiles/GameClient.dir/GameClient.c.i
.PHONY : GameClient.c.i

GameClient.s: GameClient.c.s

.PHONY : GameClient.s

# target to generate assembly for a file
GameClient.c.s:
	$(MAKE) -f CMakeFiles/GameClient.dir/build.make CMakeFiles/GameClient.dir/GameClient.c.s
.PHONY : GameClient.c.s

GameServer.o: GameServer.c.o

.PHONY : GameServer.o

# target to build an object file
GameServer.c.o:
	$(MAKE) -f CMakeFiles/GameServer.dir/build.make CMakeFiles/GameServer.dir/GameServer.c.o
.PHONY : GameServer.c.o

GameServer.i: GameServer.c.i

.PHONY : GameServer.i

# target to preprocess a source file
GameServer.c.i:
	$(MAKE) -f CMakeFiles/GameServer.dir/build.make CMakeFiles/GameServer.dir/GameServer.c.i
.PHONY : GameServer.c.i

GameServer.s: GameServer.c.s

.PHONY : GameServer.s

# target to generate assembly for a file
GameServer.c.s:
	$(MAKE) -f CMakeFiles/GameServer.dir/build.make CMakeFiles/GameServer.dir/GameServer.c.s
.PHONY : GameServer.c.s

GameUtility.o: GameUtility.c.o

.PHONY : GameUtility.o

# target to build an object file
GameUtility.c.o:
	$(MAKE) -f CMakeFiles/GameUtility.dir/build.make CMakeFiles/GameUtility.dir/GameUtility.c.o
.PHONY : GameUtility.c.o

GameUtility.i: GameUtility.c.i

.PHONY : GameUtility.i

# target to preprocess a source file
GameUtility.c.i:
	$(MAKE) -f CMakeFiles/GameUtility.dir/build.make CMakeFiles/GameUtility.dir/GameUtility.c.i
.PHONY : GameUtility.c.i

GameUtility.s: GameUtility.c.s

.PHONY : GameUtility.s

# target to generate assembly for a file
GameUtility.c.s:
	$(MAKE) -f CMakeFiles/GameUtility.dir/build.make CMakeFiles/GameUtility.dir/GameUtility.c.s
.PHONY : GameUtility.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... GameUtility"
	@echo "... GameServer"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... GameClient"
	@echo "... GameClient.o"
	@echo "... GameClient.i"
	@echo "... GameClient.s"
	@echo "... GameServer.o"
	@echo "... GameServer.i"
	@echo "... GameServer.s"
	@echo "... GameUtility.o"
	@echo "... GameUtility.i"
	@echo "... GameUtility.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

