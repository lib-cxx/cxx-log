####
# Set minimum version of CMake. Since command 'project' use
# VERSION sub-option we need 3.0.
cmake_minimum_required(VERSION 3.0)

####
# Set variables:
#   * PROJECT_NAME
#   * PROJECT_VERSION
project(cxx-log VERSION 0.1.0)

# Include config
include(Config/config.cmake)

# Include build
include(Config/build.cmake)

# Include sources
#add_subdirectory(Sources)

# Include test
add_subdirectory(Tests)
