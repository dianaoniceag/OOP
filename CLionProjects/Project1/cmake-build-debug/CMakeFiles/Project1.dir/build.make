# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /mnt/c/Users/ASUS/CLionProjects/Project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project1.dir/flags.make

CMakeFiles/Project1.dir/main.c.o: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/main.c.o: ../main.c
CMakeFiles/Project1.dir/main.c.o: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Project1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Project1.dir/main.c.o -MF CMakeFiles/Project1.dir/main.c.o.d -o CMakeFiles/Project1.dir/main.c.o -c /mnt/c/Users/ASUS/CLionProjects/Project1/main.c

CMakeFiles/Project1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/ASUS/CLionProjects/Project1/main.c > CMakeFiles/Project1.dir/main.c.i

CMakeFiles/Project1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/ASUS/CLionProjects/Project1/main.c -o CMakeFiles/Project1.dir/main.c.s

CMakeFiles/Project1.dir/Cheltuiala.c.o: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/Cheltuiala.c.o: ../Cheltuiala.c
CMakeFiles/Project1.dir/Cheltuiala.c.o: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Project1.dir/Cheltuiala.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Project1.dir/Cheltuiala.c.o -MF CMakeFiles/Project1.dir/Cheltuiala.c.o.d -o CMakeFiles/Project1.dir/Cheltuiala.c.o -c /mnt/c/Users/ASUS/CLionProjects/Project1/Cheltuiala.c

CMakeFiles/Project1.dir/Cheltuiala.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project1.dir/Cheltuiala.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/ASUS/CLionProjects/Project1/Cheltuiala.c > CMakeFiles/Project1.dir/Cheltuiala.c.i

CMakeFiles/Project1.dir/Cheltuiala.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project1.dir/Cheltuiala.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/ASUS/CLionProjects/Project1/Cheltuiala.c -o CMakeFiles/Project1.dir/Cheltuiala.c.s

CMakeFiles/Project1.dir/Controller.c.o: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/Controller.c.o: ../Controller.c
CMakeFiles/Project1.dir/Controller.c.o: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Project1.dir/Controller.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Project1.dir/Controller.c.o -MF CMakeFiles/Project1.dir/Controller.c.o.d -o CMakeFiles/Project1.dir/Controller.c.o -c /mnt/c/Users/ASUS/CLionProjects/Project1/Controller.c

CMakeFiles/Project1.dir/Controller.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project1.dir/Controller.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/ASUS/CLionProjects/Project1/Controller.c > CMakeFiles/Project1.dir/Controller.c.i

CMakeFiles/Project1.dir/Controller.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project1.dir/Controller.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/ASUS/CLionProjects/Project1/Controller.c -o CMakeFiles/Project1.dir/Controller.c.s

CMakeFiles/Project1.dir/UI.c.o: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/UI.c.o: ../UI.c
CMakeFiles/Project1.dir/UI.c.o: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Project1.dir/UI.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Project1.dir/UI.c.o -MF CMakeFiles/Project1.dir/UI.c.o.d -o CMakeFiles/Project1.dir/UI.c.o -c /mnt/c/Users/ASUS/CLionProjects/Project1/UI.c

CMakeFiles/Project1.dir/UI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project1.dir/UI.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/ASUS/CLionProjects/Project1/UI.c > CMakeFiles/Project1.dir/UI.c.i

CMakeFiles/Project1.dir/UI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project1.dir/UI.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/ASUS/CLionProjects/Project1/UI.c -o CMakeFiles/Project1.dir/UI.c.s

# Object files for target Project1
Project1_OBJECTS = \
"CMakeFiles/Project1.dir/main.c.o" \
"CMakeFiles/Project1.dir/Cheltuiala.c.o" \
"CMakeFiles/Project1.dir/Controller.c.o" \
"CMakeFiles/Project1.dir/UI.c.o"

# External object files for target Project1
Project1_EXTERNAL_OBJECTS =

Project1: CMakeFiles/Project1.dir/main.c.o
Project1: CMakeFiles/Project1.dir/Cheltuiala.c.o
Project1: CMakeFiles/Project1.dir/Controller.c.o
Project1: CMakeFiles/Project1.dir/UI.c.o
Project1: CMakeFiles/Project1.dir/build.make
Project1: CMakeFiles/Project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Project1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project1.dir/build: Project1
.PHONY : CMakeFiles/Project1.dir/build

CMakeFiles/Project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project1.dir/clean

CMakeFiles/Project1.dir/depend:
	cd /mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/ASUS/CLionProjects/Project1 /mnt/c/Users/ASUS/CLionProjects/Project1 /mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug /mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug /mnt/c/Users/ASUS/CLionProjects/Project1/cmake-build-debug/CMakeFiles/Project1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project1.dir/depend

