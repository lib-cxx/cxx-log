####
# Create targets
add_library(cxx-log 
    Sources/cxxlog/Level.cxx Sources/cxxlog/Formatter.hxx
    Sources/cxxlog/Level.cxx Sources/cxxlog/Level.hxx
    Sources/cxxlog/LoggerDelegate.hxx
    Sources/cxxlog/DefaultLoggerDelegate.cxx Sources/cxxlog/DefaultLoggerDelegate.hxx
    Sources/cxxlog/Logger.cxx Sources/cxxlog/Logger.hxx
)

####
# Properties of targets

# Add definitions for targets
# Values:
#   * Debug: -DCXX_LOG_DEBUG=1
#   * Release: -DCXX_LOG_DEBUG=0
#   * other: -DCXX_LOG_DEBUG=0
target_compile_definitions(cxx-log  PUBLIC "CXX_LOG_DEBUG=$<CONFIG:Debug>")

# Generate headers:
include(GenerateExportHeader)
generate_export_header(cxx-log)

# Global includes. Used by all targets
# Note:
#   * header location in project: Foo/Source/foo/Bar.hpp
#   * header can be included by C++ code `#include <foo/Bar.hpp>`
#   * header location in project: ${CMAKE_CURRENT_BINARY_DIR}/bar_export.hpp
#   * header can be included by: `#include <bar_export.hpp>`
target_include_directories(
    cxx-log PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Sources>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

####
# Installation (https://github.com/forexample/package-example)

# Layout. This works for all platforms:
#   * <prefix>/lib/cmake/<PROJECT-NAME>
#   * <prefix>/lib/
#   * <prefix>/include/
set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(include_install_dir "include")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# Configuration
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with fuction 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Note: PROJECT_VERSION is used as a VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Configure '<PROJECT-NAME>Config.cmake'
# Use variables:
#   * targets_export_name
#   * PROJECT_NAME
configure_package_config_file(
    "cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

# Targets:
#   * <prefix>/lib/cxx-log.a
#   * header location after install: <prefix>/include/foo/Bar.hpp
#   * headers can be included by C++ code `#include <foo/Bar.hpp>`
install(
    TARGETS cxx-log
    EXPORT "${targets_export_name}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

# Headers:
#   * Source/foo/Bar.hpp -> <prefix>/include/foo/Bar.hpp
#   * Source/foo/Baz.hpp -> <prefix>/include/foo/Baz.hpp
install(
    DIRECTORY "Sources/cxxlog"
    DESTINATION "${include_install_dir}"
    FILES_MATCHING PATTERN "*.hxx"
)

# Export headers:
#   * ${CMAKE_CURRENT_BINARY_DIR}/bar_export.h -> <prefix>/include/bar_export.h
#   * ${CMAKE_CURRENT_BINARY_DIR}/baz_export.h -> <prefix>/include/baz_export.h
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cxx-log_export.h"
    DESTINATION "${include_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/Foo/FooConfig.cmake
#   * <prefix>/lib/cmake/Foo/FooConfigVersion.cmake
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/Foo/FooTargets.cmake
install(
    EXPORT "${targets_export_name}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)
