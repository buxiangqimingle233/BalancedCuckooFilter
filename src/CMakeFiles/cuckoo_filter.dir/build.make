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
CMAKE_SOURCE_DIR = /home/wangzhao/code/cuckoo_hash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wangzhao/code/cuckoo_hash

# Include any dependencies generated for this target.
include src/CMakeFiles/cuckoo_filter.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/cuckoo_filter.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/cuckoo_filter.dir/flags.make

src/CMakeFiles/cuckoo_filter.dir/main.cpp.o: src/CMakeFiles/cuckoo_filter.dir/flags.make
src/CMakeFiles/cuckoo_filter.dir/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzhao/code/cuckoo_hash/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/cuckoo_filter.dir/main.cpp.o"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cuckoo_filter.dir/main.cpp.o -c /home/wangzhao/code/cuckoo_hash/src/main.cpp

src/CMakeFiles/cuckoo_filter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cuckoo_filter.dir/main.cpp.i"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzhao/code/cuckoo_hash/src/main.cpp > CMakeFiles/cuckoo_filter.dir/main.cpp.i

src/CMakeFiles/cuckoo_filter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cuckoo_filter.dir/main.cpp.s"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzhao/code/cuckoo_hash/src/main.cpp -o CMakeFiles/cuckoo_filter.dir/main.cpp.s

src/CMakeFiles/cuckoo_filter.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/cuckoo_filter.dir/main.cpp.o.requires

src/CMakeFiles/cuckoo_filter.dir/main.cpp.o.provides: src/CMakeFiles/cuckoo_filter.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/cuckoo_filter.dir/build.make src/CMakeFiles/cuckoo_filter.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/cuckoo_filter.dir/main.cpp.o.provides

src/CMakeFiles/cuckoo_filter.dir/main.cpp.o.provides.build: src/CMakeFiles/cuckoo_filter.dir/main.cpp.o


src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o: src/CMakeFiles/cuckoo_filter.dir/flags.make
src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o: src/collect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzhao/code/cuckoo_hash/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cuckoo_filter.dir/collect.cpp.o -c /home/wangzhao/code/cuckoo_hash/src/collect.cpp

src/CMakeFiles/cuckoo_filter.dir/collect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cuckoo_filter.dir/collect.cpp.i"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzhao/code/cuckoo_hash/src/collect.cpp > CMakeFiles/cuckoo_filter.dir/collect.cpp.i

src/CMakeFiles/cuckoo_filter.dir/collect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cuckoo_filter.dir/collect.cpp.s"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzhao/code/cuckoo_hash/src/collect.cpp -o CMakeFiles/cuckoo_filter.dir/collect.cpp.s

src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o.requires:

.PHONY : src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o.requires

src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o.provides: src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/cuckoo_filter.dir/build.make src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o.provides.build
.PHONY : src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o.provides

src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o.provides.build: src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o


src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o: src/CMakeFiles/cuckoo_filter.dir/flags.make
src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o: src/cuckoo_filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzhao/code/cuckoo_hash/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o -c /home/wangzhao/code/cuckoo_hash/src/cuckoo_filter.cpp

src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.i"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzhao/code/cuckoo_hash/src/cuckoo_filter.cpp > CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.i

src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.s"
	cd /home/wangzhao/code/cuckoo_hash/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzhao/code/cuckoo_hash/src/cuckoo_filter.cpp -o CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.s

src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o.requires:

.PHONY : src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o.requires

src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o.provides: src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/cuckoo_filter.dir/build.make src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o.provides.build
.PHONY : src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o.provides

src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o.provides.build: src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o


# Object files for target cuckoo_filter
cuckoo_filter_OBJECTS = \
"CMakeFiles/cuckoo_filter.dir/main.cpp.o" \
"CMakeFiles/cuckoo_filter.dir/collect.cpp.o" \
"CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o"

# External object files for target cuckoo_filter
cuckoo_filter_EXTERNAL_OBJECTS =

bin/cuckoo_filter: src/CMakeFiles/cuckoo_filter.dir/main.cpp.o
bin/cuckoo_filter: src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o
bin/cuckoo_filter: src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o
bin/cuckoo_filter: src/CMakeFiles/cuckoo_filter.dir/build.make
bin/cuckoo_filter: lib/libxxhash.a
bin/cuckoo_filter: libcityhash.a
bin/cuckoo_filter: src/CMakeFiles/cuckoo_filter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wangzhao/code/cuckoo_hash/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/cuckoo_filter"
	cd /home/wangzhao/code/cuckoo_hash/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cuckoo_filter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/cuckoo_filter.dir/build: bin/cuckoo_filter

.PHONY : src/CMakeFiles/cuckoo_filter.dir/build

src/CMakeFiles/cuckoo_filter.dir/requires: src/CMakeFiles/cuckoo_filter.dir/main.cpp.o.requires
src/CMakeFiles/cuckoo_filter.dir/requires: src/CMakeFiles/cuckoo_filter.dir/collect.cpp.o.requires
src/CMakeFiles/cuckoo_filter.dir/requires: src/CMakeFiles/cuckoo_filter.dir/cuckoo_filter.cpp.o.requires

.PHONY : src/CMakeFiles/cuckoo_filter.dir/requires

src/CMakeFiles/cuckoo_filter.dir/clean:
	cd /home/wangzhao/code/cuckoo_hash/src && $(CMAKE_COMMAND) -P CMakeFiles/cuckoo_filter.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/cuckoo_filter.dir/clean

src/CMakeFiles/cuckoo_filter.dir/depend:
	cd /home/wangzhao/code/cuckoo_hash && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wangzhao/code/cuckoo_hash /home/wangzhao/code/cuckoo_hash/src /home/wangzhao/code/cuckoo_hash /home/wangzhao/code/cuckoo_hash/src /home/wangzhao/code/cuckoo_hash/src/CMakeFiles/cuckoo_filter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/cuckoo_filter.dir/depend

