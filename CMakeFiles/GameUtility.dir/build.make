# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame"

# Include any dependencies generated for this target.
include CMakeFiles/GameUtility.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GameUtility.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameUtility.dir/flags.make

CMakeFiles/GameUtility.dir/GameUtility.c.o: CMakeFiles/GameUtility.dir/flags.make
CMakeFiles/GameUtility.dir/GameUtility.c.o: GameUtility.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GameUtility.dir/GameUtility.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GameUtility.dir/GameUtility.c.o   -c "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/GameUtility.c"

CMakeFiles/GameUtility.dir/GameUtility.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GameUtility.dir/GameUtility.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/GameUtility.c" > CMakeFiles/GameUtility.dir/GameUtility.c.i

CMakeFiles/GameUtility.dir/GameUtility.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GameUtility.dir/GameUtility.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/GameUtility.c" -o CMakeFiles/GameUtility.dir/GameUtility.c.s

CMakeFiles/GameUtility.dir/GameUtility.c.o.requires:

.PHONY : CMakeFiles/GameUtility.dir/GameUtility.c.o.requires

CMakeFiles/GameUtility.dir/GameUtility.c.o.provides: CMakeFiles/GameUtility.dir/GameUtility.c.o.requires
	$(MAKE) -f CMakeFiles/GameUtility.dir/build.make CMakeFiles/GameUtility.dir/GameUtility.c.o.provides.build
.PHONY : CMakeFiles/GameUtility.dir/GameUtility.c.o.provides

CMakeFiles/GameUtility.dir/GameUtility.c.o.provides.build: CMakeFiles/GameUtility.dir/GameUtility.c.o


# Object files for target GameUtility
GameUtility_OBJECTS = \
"CMakeFiles/GameUtility.dir/GameUtility.c.o"

# External object files for target GameUtility
GameUtility_EXTERNAL_OBJECTS =

libGameUtility.dylib: CMakeFiles/GameUtility.dir/GameUtility.c.o
libGameUtility.dylib: CMakeFiles/GameUtility.dir/build.make
libGameUtility.dylib: CMakeFiles/GameUtility.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libGameUtility.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameUtility.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameUtility.dir/build: libGameUtility.dylib

.PHONY : CMakeFiles/GameUtility.dir/build

CMakeFiles/GameUtility.dir/requires: CMakeFiles/GameUtility.dir/GameUtility.c.o.requires

.PHONY : CMakeFiles/GameUtility.dir/requires

CMakeFiles/GameUtility.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameUtility.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameUtility.dir/clean

CMakeFiles/GameUtility.dir/depend:
	cd "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame" "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame" "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame" "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame" "/Users/Luca/Desktop/Universita'/Informatica Laboratorio/GooseGame/CMakeFiles/GameUtility.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GameUtility.dir/depend

