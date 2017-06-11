cmake_minimum_required(VERSION 3.0.0)

# Define project name
project(cxx-log)

# Include config
include(Config/config.cmake)

# Include sources
add_subdirectory(Sources)

# Include test
add_subdirectory(Tests)
