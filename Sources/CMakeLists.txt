# Boost
find_package (Boost 1.54.0 REQUIRED)

# Create library
add_library(${PROJECT_NAME} 
    cxxlog/Level.cxx cxxlog/Formatter.hxx
    cxxlog/Level.cxx cxxlog/Level.hxx
    cxxlog/LoggerDelegate.hxx
    cxxlog/DefaultLoggerDelegate.cxx cxxlog/DefaultLoggerDelegate.hxx
    cxxlog/Logger.cxx cxxlog/Logger.hxx
)

# Include boost headers
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})

# Set headers
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER 
    "cxxlog/Formatter.hxx;cxxlog/Level.hxx;cxxlog/LoggerDelegate.hxx;cxxlog/DefaultLoggerDelegate.hxx;cxxlog/Logger.hxx"
)

# Install cxx-log on systm
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/cxx-log
    PUBLIC_HEADER DESTINATION include/cxx-log
)

# Install cxx-log as cmake dependency
install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
)

# Create version file
include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
    VERSION 0.1
    COMPATIBILITY SameMajorVersion
)

#Install version file
#install(FILES "${PROJECT_NAME}ConfigVersion.cmake" "${PROJECT_NAME}ConfigVersion.cmake"
#    DESTINATION lib/cmake/${PROJECT_NAME}
#)
