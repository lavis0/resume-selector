cmake_minimum_required(VERSION 3.31)

project(external LANGUAGES CXX)

# from CMake module 'ExternalProject'.
include(ExternalProject)

set(EXTERNAL_PROJECT_CMAKE_ARGS
        -DCMAKE_CXX_COMPILER:PATH=${CMAKE_CXX_COMPILER}
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX})


ExternalProject_Add(googletest
        PREFIX "extern"
        GIT_REPOSITORY "https://github.com/google/googletest"
        GIT_TAG "v1.14.0"
        GIT_SHALLOW TRUE
        CMAKE_ARGS ${EXTERNAL_PROJECT_CMAKE_ARGS}
)
