
# Add sources files
set (${PROJECT_NAME}_SOURCES
    cxxlog/Level.cxx cxxlog/Formatter.hxx
    cxxlog/Level.cxx cxxlog/Level.hxx
    cxxlog/LoggerDelegate.hxx
    cxxlog/DefaultLoggerDelegate.cxx cxxlog/DefaultLoggerDelegate.hxx
    cxxlog/Logger.cxx cxxlog/Logger.hxx
)

# Create library
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

# Install exec in bin directory
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
