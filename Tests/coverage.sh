
#!/bin/bash

export CXX=g++

# Projects
SCRIPT_DIRECTORY=`dirname "$0"`
PROJECT_DIRECTORY=`readlink -f "$SCRIPT_DIRECTORY/.."`

# Build directory
BUILD_DIRECTORY="${PROJECT_DIRECTORY}/build-report"

# Source directory
SOURCES_DIRECTORY="${PROJECT_DIRECTORY}/Sources"

echo " - Init build directory : ${BUILD_DIRECTORY}"

# Go to build directory
mkdir -p ${BUILD_DIRECTORY}

echo " - Enter to build directory"

cd ${BUILD_DIRECTORY}

echo " - Init cmake"

# Init coverage
cmake -DCMAKE_BUILD_TYPE=Coverage ${PROJECT_DIRECTORY}

echo " - Clean directory : "`pwd`

# Netoyage
rm -fr out
rm -f *.info
make clean

echo " - Build"

# Build
make

echo " - Launch test : make test"

# Launch test
make test

echo " - Collect lcov : lcov -f -c --directory ${BUILD_DIRECTORY} -o app_test.info"

# Collect coverage
lcov -f -c --directory ${BUILD_DIRECTORY} -o app_test.info

echo " - Filter ${SOURCES_DIRECTORY} : lcov -e app_test.info "${SOURCES_DIRECTORY}/*" -o result.info"

# Filter results
lcov -e app_test.info "${SOURCES_DIRECTORY}/*" -o result.info

echo " - Generate report "`pwd`"/out : genhtml result.info --output-directory out"

# Generate HTML result
genhtml result.info --output-directory out
