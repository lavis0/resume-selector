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
set(COMMON_SOURCES
    lib/Common/Version.cpp)

set(RESUME_SOURCES
        lib/Resume/ResumeData.cpp)

#set(STORAGE_SOURCES
#        lib/Storage/CSVReader.cpp
#        lib/Storage/CSVWriter.cpp)

#set(LATEX_SOURCES
#        lib/LaTeX/LaTeXGenerator.cpp
#        lib/LaTeX/TemplateManager.cpp
#        lib/LaTeX/PDFCompiler.cpp)

add_library(resume_core STATIC
        ${COMMON_SOURCES}
        ${RESUME_SOURCES})
#        ${STORAGE_SOURCES}
#        ${LATEX_SOURCES})

target_compile_features(resume_core PUBLIC cxx_std_20)
target_include_directories(resume_core
        PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Utilities
add_executable(selector-getVersion src/utils/getVersion.cpp)
target_link_libraries(selector-getVersion resume_core)

# Main application
add_executable(resume-cli src/main.cpp)
target_link_libraries(resume-cli resume_core)


# ===================================================================
# Testing
# -------------------------------------------------------------------

add_executable(selector-test tests/main.cpp)
target_link_libraries(selector-test GTest::gtest resume_core)
add_custom_target(check
        COMMAND selector-test --gtest_color=yes --gtest_output=xml:selector-test.xml
)