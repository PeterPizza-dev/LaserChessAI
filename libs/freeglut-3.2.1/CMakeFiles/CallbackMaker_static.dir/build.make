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
CMAKE_SOURCE_DIR = /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1

# Include any dependencies generated for this target.
include CMakeFiles/CallbackMaker_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CallbackMaker_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CallbackMaker_static.dir/flags.make

CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o: CMakeFiles/CallbackMaker_static.dir/flags.make
CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o: progs/demos/CallbackMaker/CallbackMaker.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o   -c /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/progs/demos/CallbackMaker/CallbackMaker.c

CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/progs/demos/CallbackMaker/CallbackMaker.c > CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.i

CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/progs/demos/CallbackMaker/CallbackMaker.c -o CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.s

CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o.requires:

.PHONY : CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o.requires

CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o.provides: CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o.requires
	$(MAKE) -f CMakeFiles/CallbackMaker_static.dir/build.make CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o.provides.build
.PHONY : CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o.provides

CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o.provides.build: CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o


# Object files for target CallbackMaker_static
CallbackMaker_static_OBJECTS = \
"CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o"

# External object files for target CallbackMaker_static
CallbackMaker_static_EXTERNAL_OBJECTS =

bin/CallbackMaker_static: CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o
bin/CallbackMaker_static: CMakeFiles/CallbackMaker_static.dir/build.make
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libGL.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libX11.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libXrandr.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libXi.so
bin/CallbackMaker_static: lib/libglut.a
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libGL.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libX11.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libXrandr.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
bin/CallbackMaker_static: /usr/lib/x86_64-linux-gnu/libXi.so
bin/CallbackMaker_static: CMakeFiles/CallbackMaker_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/CallbackMaker_static"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CallbackMaker_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CallbackMaker_static.dir/build: bin/CallbackMaker_static

.PHONY : CMakeFiles/CallbackMaker_static.dir/build

CMakeFiles/CallbackMaker_static.dir/requires: CMakeFiles/CallbackMaker_static.dir/progs/demos/CallbackMaker/CallbackMaker.c.o.requires

.PHONY : CMakeFiles/CallbackMaker_static.dir/requires

CMakeFiles/CallbackMaker_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CallbackMaker_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CallbackMaker_static.dir/clean

CMakeFiles/CallbackMaker_static.dir/depend:
	cd /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/CMakeFiles/CallbackMaker_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CallbackMaker_static.dir/depend

