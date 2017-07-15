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

####
# Create targets
add_library(cxx-log 
    Sources/cxx-log/Level.cxx Sources/cxx-log/Formatter.hxx
    Sources/cxx-log/Level.cxx Sources/cxx-log/Level.hxx
    Sources/cxx-log/LoggerDelegate.hxx
    Sources/cxx-log/DefaultLoggerDelegate.cxx Sources/cxx-log/DefaultLoggerDelegate.hxx
    Sources/cxx-log/Logger.cxx Sources/cxx-log/Logger.hxx
)

# Include build
include(Config/build.cmake)

# Include test
add_subdirectory(Tests)
