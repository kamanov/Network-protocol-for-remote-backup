# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c

# Include any dependencies generated for this target.
include CMakeFiles/msgpack-static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/msgpack-static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/msgpack-static.dir/flags.make

CMakeFiles/msgpack-static.dir/src/unpack.c.o: CMakeFiles/msgpack-static.dir/flags.make
CMakeFiles/msgpack-static.dir/src/unpack.c.o: src/unpack.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/msgpack-static.dir/src/unpack.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/msgpack-static.dir/src/unpack.c.o   -c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/unpack.c

CMakeFiles/msgpack-static.dir/src/unpack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgpack-static.dir/src/unpack.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/unpack.c > CMakeFiles/msgpack-static.dir/src/unpack.c.i

CMakeFiles/msgpack-static.dir/src/unpack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgpack-static.dir/src/unpack.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/unpack.c -o CMakeFiles/msgpack-static.dir/src/unpack.c.s

CMakeFiles/msgpack-static.dir/src/unpack.c.o.requires:
.PHONY : CMakeFiles/msgpack-static.dir/src/unpack.c.o.requires

CMakeFiles/msgpack-static.dir/src/unpack.c.o.provides: CMakeFiles/msgpack-static.dir/src/unpack.c.o.requires
	$(MAKE) -f CMakeFiles/msgpack-static.dir/build.make CMakeFiles/msgpack-static.dir/src/unpack.c.o.provides.build
.PHONY : CMakeFiles/msgpack-static.dir/src/unpack.c.o.provides

CMakeFiles/msgpack-static.dir/src/unpack.c.o.provides.build: CMakeFiles/msgpack-static.dir/src/unpack.c.o

CMakeFiles/msgpack-static.dir/src/objectc.c.o: CMakeFiles/msgpack-static.dir/flags.make
CMakeFiles/msgpack-static.dir/src/objectc.c.o: src/objectc.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/msgpack-static.dir/src/objectc.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/msgpack-static.dir/src/objectc.c.o   -c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/objectc.c

CMakeFiles/msgpack-static.dir/src/objectc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgpack-static.dir/src/objectc.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/objectc.c > CMakeFiles/msgpack-static.dir/src/objectc.c.i

CMakeFiles/msgpack-static.dir/src/objectc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgpack-static.dir/src/objectc.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/objectc.c -o CMakeFiles/msgpack-static.dir/src/objectc.c.s

CMakeFiles/msgpack-static.dir/src/objectc.c.o.requires:
.PHONY : CMakeFiles/msgpack-static.dir/src/objectc.c.o.requires

CMakeFiles/msgpack-static.dir/src/objectc.c.o.provides: CMakeFiles/msgpack-static.dir/src/objectc.c.o.requires
	$(MAKE) -f CMakeFiles/msgpack-static.dir/build.make CMakeFiles/msgpack-static.dir/src/objectc.c.o.provides.build
.PHONY : CMakeFiles/msgpack-static.dir/src/objectc.c.o.provides

CMakeFiles/msgpack-static.dir/src/objectc.c.o.provides.build: CMakeFiles/msgpack-static.dir/src/objectc.c.o

CMakeFiles/msgpack-static.dir/src/version.c.o: CMakeFiles/msgpack-static.dir/flags.make
CMakeFiles/msgpack-static.dir/src/version.c.o: src/version.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/msgpack-static.dir/src/version.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/msgpack-static.dir/src/version.c.o   -c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/version.c

CMakeFiles/msgpack-static.dir/src/version.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgpack-static.dir/src/version.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/version.c > CMakeFiles/msgpack-static.dir/src/version.c.i

CMakeFiles/msgpack-static.dir/src/version.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgpack-static.dir/src/version.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/version.c -o CMakeFiles/msgpack-static.dir/src/version.c.s

CMakeFiles/msgpack-static.dir/src/version.c.o.requires:
.PHONY : CMakeFiles/msgpack-static.dir/src/version.c.o.requires

CMakeFiles/msgpack-static.dir/src/version.c.o.provides: CMakeFiles/msgpack-static.dir/src/version.c.o.requires
	$(MAKE) -f CMakeFiles/msgpack-static.dir/build.make CMakeFiles/msgpack-static.dir/src/version.c.o.provides.build
.PHONY : CMakeFiles/msgpack-static.dir/src/version.c.o.provides

CMakeFiles/msgpack-static.dir/src/version.c.o.provides.build: CMakeFiles/msgpack-static.dir/src/version.c.o

CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o: CMakeFiles/msgpack-static.dir/flags.make
CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o: src/vrefbuffer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o   -c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/vrefbuffer.c

CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/vrefbuffer.c > CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.i

CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/vrefbuffer.c -o CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.s

CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o.requires:
.PHONY : CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o.requires

CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o.provides: CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o.requires
	$(MAKE) -f CMakeFiles/msgpack-static.dir/build.make CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o.provides.build
.PHONY : CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o.provides

CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o.provides.build: CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o

CMakeFiles/msgpack-static.dir/src/zone.c.o: CMakeFiles/msgpack-static.dir/flags.make
CMakeFiles/msgpack-static.dir/src/zone.c.o: src/zone.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/msgpack-static.dir/src/zone.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/msgpack-static.dir/src/zone.c.o   -c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/zone.c

CMakeFiles/msgpack-static.dir/src/zone.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msgpack-static.dir/src/zone.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/zone.c > CMakeFiles/msgpack-static.dir/src/zone.c.i

CMakeFiles/msgpack-static.dir/src/zone.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msgpack-static.dir/src/zone.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/src/zone.c -o CMakeFiles/msgpack-static.dir/src/zone.c.s

CMakeFiles/msgpack-static.dir/src/zone.c.o.requires:
.PHONY : CMakeFiles/msgpack-static.dir/src/zone.c.o.requires

CMakeFiles/msgpack-static.dir/src/zone.c.o.provides: CMakeFiles/msgpack-static.dir/src/zone.c.o.requires
	$(MAKE) -f CMakeFiles/msgpack-static.dir/build.make CMakeFiles/msgpack-static.dir/src/zone.c.o.provides.build
.PHONY : CMakeFiles/msgpack-static.dir/src/zone.c.o.provides

CMakeFiles/msgpack-static.dir/src/zone.c.o.provides.build: CMakeFiles/msgpack-static.dir/src/zone.c.o

# Object files for target msgpack-static
msgpack__static_OBJECTS = \
"CMakeFiles/msgpack-static.dir/src/unpack.c.o" \
"CMakeFiles/msgpack-static.dir/src/objectc.c.o" \
"CMakeFiles/msgpack-static.dir/src/version.c.o" \
"CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o" \
"CMakeFiles/msgpack-static.dir/src/zone.c.o"

# External object files for target msgpack-static
msgpack__static_EXTERNAL_OBJECTS =

libmsgpack.a: CMakeFiles/msgpack-static.dir/src/unpack.c.o
libmsgpack.a: CMakeFiles/msgpack-static.dir/src/objectc.c.o
libmsgpack.a: CMakeFiles/msgpack-static.dir/src/version.c.o
libmsgpack.a: CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o
libmsgpack.a: CMakeFiles/msgpack-static.dir/src/zone.c.o
libmsgpack.a: CMakeFiles/msgpack-static.dir/build.make
libmsgpack.a: CMakeFiles/msgpack-static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libmsgpack.a"
	$(CMAKE_COMMAND) -P CMakeFiles/msgpack-static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/msgpack-static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/msgpack-static.dir/build: libmsgpack.a
.PHONY : CMakeFiles/msgpack-static.dir/build

CMakeFiles/msgpack-static.dir/requires: CMakeFiles/msgpack-static.dir/src/unpack.c.o.requires
CMakeFiles/msgpack-static.dir/requires: CMakeFiles/msgpack-static.dir/src/objectc.c.o.requires
CMakeFiles/msgpack-static.dir/requires: CMakeFiles/msgpack-static.dir/src/version.c.o.requires
CMakeFiles/msgpack-static.dir/requires: CMakeFiles/msgpack-static.dir/src/vrefbuffer.c.o.requires
CMakeFiles/msgpack-static.dir/requires: CMakeFiles/msgpack-static.dir/src/zone.c.o.requires
.PHONY : CMakeFiles/msgpack-static.dir/requires

CMakeFiles/msgpack-static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/msgpack-static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/msgpack-static.dir/clean

CMakeFiles/msgpack-static.dir/depend:
	cd /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c /Users/karama/Spbau/diploma/backup-networks.main/protocol/impl/msgpack-c/CMakeFiles/msgpack-static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/msgpack-static.dir/depend

