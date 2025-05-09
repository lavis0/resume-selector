cmake_minimum_required(VERSION 3.31)
project(resume_selector)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")
set(EXTERNAL_PROJECT_CMAKE_ARGS
      -G ${CMAKE_GENERATOR}
      -DCMAKE_CXX_COMPILER:PATH=${CMAKE_CXX_COMPILER}
      -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
      -DCMAKE_INSTALL_PREFIX:PATH=${BUILD_DIR})

# Download and configure our external dependencies
execute_process(
  COMMAND ${CMAKE_COMMAND}
      -S ${CMAKE_SOURCE_DIR}/extern
      -B ${BUILD_DIR}/extern
      ${EXTERNAL_PROJECT_CMAKE_ARGS}
)

# Build our external dependencies.
execute_process(
  COMMAND ${CMAKE_COMMAND} --build ${BUILD_DIR}/extern
)
# Install our external dependencies.
execute_process(
  COMMAND ${CMAKE_COMMAND} --install ${BUILD_DIR}/extern
)

set(GTest_DIR "${BUILD_DIR}/lib/cmake/GTest"
    CACHE PATH "Path to the googletest package configuration files")
find_package(GTest REQUIRED
  CONFIG
  NO_DEFAULT_PATH
  NO_PACKAGE_ROOT_PATH
  NO_SYSTEM_ENVIRONMENT_PATH
)

# ==================================================================
# Libraries and executables
# -------------------------------------------------------------------

add_library(resume_selector STATIC lib/Common/Version.cpp)
target_compile_features(resume_selector PUBLIC cxx_std_20)
target_include_directories(resume_selector
        PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(selector-getVersion src/utils/getVersion.cpp)
target_link_libraries(selector-getVersion resume_selector)

# ===================================================================
# Testing
# -------------------------------------------------------------------

add_executable(selector-test tests/main.cpp)
target_link_libraries(selector-test GTest::gtest resume_selector)
add_custom_target(check
        COMMAND selector-test --gtest_color=yes --gtest_output=xml:selector-test.xml
)