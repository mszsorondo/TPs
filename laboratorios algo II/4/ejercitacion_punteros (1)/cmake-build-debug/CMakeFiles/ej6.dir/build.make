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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ej6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej6.dir/flags.make

CMakeFiles/ej6.dir/tests/sdm_tests.cpp.o: CMakeFiles/ej6.dir/flags.make
CMakeFiles/ej6.dir/tests/sdm_tests.cpp.o: ../tests/sdm_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej6.dir/tests/sdm_tests.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej6.dir/tests/sdm_tests.cpp.o -c "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/tests/sdm_tests.cpp"

CMakeFiles/ej6.dir/tests/sdm_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej6.dir/tests/sdm_tests.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/tests/sdm_tests.cpp" > CMakeFiles/ej6.dir/tests/sdm_tests.cpp.i

CMakeFiles/ej6.dir/tests/sdm_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej6.dir/tests/sdm_tests.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/tests/sdm_tests.cpp" -o CMakeFiles/ej6.dir/tests/sdm_tests.cpp.s

CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.o: CMakeFiles/ej6.dir/flags.make
CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.o: ../src/SistemaDeMensajes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.o -c "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/SistemaDeMensajes.cpp"

CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/SistemaDeMensajes.cpp" > CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.i

CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/SistemaDeMensajes.cpp" -o CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.s

CMakeFiles/ej6.dir/src/Proxy2.cpp.o: CMakeFiles/ej6.dir/flags.make
CMakeFiles/ej6.dir/src/Proxy2.cpp.o: ../src/Proxy2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ej6.dir/src/Proxy2.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej6.dir/src/Proxy2.cpp.o -c "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/Proxy2.cpp"

CMakeFiles/ej6.dir/src/Proxy2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej6.dir/src/Proxy2.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/Proxy2.cpp" > CMakeFiles/ej6.dir/src/Proxy2.cpp.i

CMakeFiles/ej6.dir/src/Proxy2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej6.dir/src/Proxy2.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/Proxy2.cpp" -o CMakeFiles/ej6.dir/src/Proxy2.cpp.s

CMakeFiles/ej6.dir/src/Internet.cpp.o: CMakeFiles/ej6.dir/flags.make
CMakeFiles/ej6.dir/src/Internet.cpp.o: ../src/Internet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ej6.dir/src/Internet.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej6.dir/src/Internet.cpp.o -c "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/Internet.cpp"

CMakeFiles/ej6.dir/src/Internet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej6.dir/src/Internet.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/Internet.cpp" > CMakeFiles/ej6.dir/src/Internet.cpp.i

CMakeFiles/ej6.dir/src/Internet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej6.dir/src/Internet.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/Internet.cpp" -o CMakeFiles/ej6.dir/src/Internet.cpp.s

CMakeFiles/ej6.dir/src/ConexionJugador.cpp.o: CMakeFiles/ej6.dir/flags.make
CMakeFiles/ej6.dir/src/ConexionJugador.cpp.o: ../src/ConexionJugador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ej6.dir/src/ConexionJugador.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej6.dir/src/ConexionJugador.cpp.o -c "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/ConexionJugador.cpp"

CMakeFiles/ej6.dir/src/ConexionJugador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej6.dir/src/ConexionJugador.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/ConexionJugador.cpp" > CMakeFiles/ej6.dir/src/ConexionJugador.cpp.i

CMakeFiles/ej6.dir/src/ConexionJugador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej6.dir/src/ConexionJugador.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/src/ConexionJugador.cpp" -o CMakeFiles/ej6.dir/src/ConexionJugador.cpp.s

# Object files for target ej6
ej6_OBJECTS = \
"CMakeFiles/ej6.dir/tests/sdm_tests.cpp.o" \
"CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.o" \
"CMakeFiles/ej6.dir/src/Proxy2.cpp.o" \
"CMakeFiles/ej6.dir/src/Internet.cpp.o" \
"CMakeFiles/ej6.dir/src/ConexionJugador.cpp.o"

# External object files for target ej6
ej6_EXTERNAL_OBJECTS =

ej6: CMakeFiles/ej6.dir/tests/sdm_tests.cpp.o
ej6: CMakeFiles/ej6.dir/src/SistemaDeMensajes.cpp.o
ej6: CMakeFiles/ej6.dir/src/Proxy2.cpp.o
ej6: CMakeFiles/ej6.dir/src/Internet.cpp.o
ej6: CMakeFiles/ej6.dir/src/ConexionJugador.cpp.o
ej6: CMakeFiles/ej6.dir/build.make
ej6: libgtest.a
ej6: libgtest_main.a
ej6: CMakeFiles/ej6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ej6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej6.dir/build: ej6

.PHONY : CMakeFiles/ej6.dir/build

CMakeFiles/ej6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej6.dir/clean

CMakeFiles/ej6.dir/depend:
	cd "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)" "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)" "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug" "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug" "/home/msorondo/Desktop/Finales/laboratorios algo II/4/ejercitacion_punteros (1)/cmake-build-debug/CMakeFiles/ej6.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ej6.dir/depend

