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
include CMakeFiles/Lorenz_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lorenz_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lorenz_static.dir/flags.make

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o: CMakeFiles/Lorenz_static.dir/flags.make
CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o: progs/demos/Lorenz/lorenz.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o   -c /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/progs/demos/Lorenz/lorenz.c

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/progs/demos/Lorenz/lorenz.c > CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.i

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/progs/demos/Lorenz/lorenz.c -o CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.s

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o.requires:

.PHONY : CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o.requires

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o.provides: CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o.requires
	$(MAKE) -f CMakeFiles/Lorenz_static.dir/build.make CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o.provides.build
.PHONY : CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o.provides

CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o.provides.build: CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o


# Object files for target Lorenz_static
Lorenz_static_OBJECTS = \
"CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o"

# External object files for target Lorenz_static
Lorenz_static_EXTERNAL_OBJECTS =

bin/Lorenz_static: CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o
bin/Lorenz_static: CMakeFiles/Lorenz_static.dir/build.make
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libGL.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libX11.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libXrandr.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libXi.so
bin/Lorenz_static: lib/libglut.a
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libGL.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libX11.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libXrandr.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
bin/Lorenz_static: /usr/lib/x86_64-linux-gnu/libXi.so
bin/Lorenz_static: CMakeFiles/Lorenz_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/Lorenz_static"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lorenz_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lorenz_static.dir/build: bin/Lorenz_static

.PHONY : CMakeFiles/Lorenz_static.dir/build

CMakeFiles/Lorenz_static.dir/requires: CMakeFiles/Lorenz_static.dir/progs/demos/Lorenz/lorenz.c.o.requires

.PHONY : CMakeFiles/Lorenz_static.dir/requires

CMakeFiles/Lorenz_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lorenz_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lorenz_static.dir/clean

CMakeFiles/Lorenz_static.dir/depend:
	cd /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1 /home/sean/kunstigInt/assignment/LaserChessAI/libs/freeglut-3.2.1/CMakeFiles/Lorenz_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lorenz_static.dir/depend

