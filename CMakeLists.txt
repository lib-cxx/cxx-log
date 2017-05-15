cmake_minimum_required(VERSION 3.0.0)

# Define project name
project(cxxlog)

# Enable testing capability
enable_testing()

# Set C++ compatibility
set(CMAKE_CXX_STANDARD 17)

# Define CXX flags
set(CXX_FLAGS -Wall -pedantic)

# Create test coverage target (gcov)
if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
	set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
    set(CXX_FLAGS ${CXX_FLAGS} --coverage  -fprofile-arcs -ftest-coverage)
	set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " --coverage  -fprofile-arcs -ftest-coverage")
endif()

# Set compilation flags
add_definitions(${CXX_FLAGS})

# Include dependencies
add_subdirectory(Dependencies)

# Include sources
add_subdirectory(Sources)

# Include test
add_subdirectory(Tests)
