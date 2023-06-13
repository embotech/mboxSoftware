cmake_minimum_required(VERSION 3.13)
project(mBoxSW)
message(STATUS "Configuring mBox software for ${CMAKE_SYSTEM_PROCESSOR} system.")

# ############################################################################################################
# Prepare Configuration

include(GoogleTest)
include(cmake/CheckGit.cmake)

enable_language(C CXX)

find_package(Threads)

# ############################################################################################################
# A few settings

# Set verbose mode for the compilation process
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set C90 requirement
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)

# Set C++14 requirement
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# GCC Settings
if(CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_EXTENSIONS ON)
    set(CMAKE_CXX_EXTENSIONS ON)

    # Need position-independent code for Linux
    set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
endif()

# ############################################################################################################
# Prepare testing
enable_testing()

if(MSVC)
    set(gtest_force_shared_crt
        ON
        CACHE BOOL "" FORCE)
endif()

# Add dependency.
if(NOT GOOGLETEST_PATH)
    set(GOOGLETEST_PATH "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/gtest")
endif()

if(NOT TARGET gtest)
    add_subdirectory(${GOOGLETEST_PATH} ${CMAKE_CURRENT_BINARY_DIR}/googletest EXCLUDE_FROM_ALL)
endif()

# Unit test target
if(CMAKE_TESTING_ENABLED)
    add_executable(obrttgUnitTests)
    target_link_libraries(obrttgUnitTests PRIVATE gtest gmock gtest_main rt)

    if(CMAKE_C_COMPILER_ID MATCHES "GNU" OR CMAKE_C_COMPILER_ID MATCHES "Clang")
        # Suppress unnecessary GCC warning that appears in Google Test code. See
        # https://github.com/google/googletest/issues/2271
        target_compile_options(obrttgUnitTests PRIVATE -Wno-gnu-zero-variadic-macro-arguments)
    endif()
    # This automatically adds all tests within unitTests executable as separate CTests.
    if(NOT CMAKE_CROSSCOMPILING)
        gtest_discover_tests(obrttgUnitTests)
    endif()
endif()

# Update build hash (=> git hash)
CheckGitSetup()
add_library(Obrttg STATIC)


add_subdirectory(dependencies)
add_subdirectory(utils)
add_subdirectory(obrttg)
add_subdirectory(codegen)
add_subdirectory(communication)
add_subdirectory(logging)
add_subdirectory(main)

get_target_property(OBRTTG_SOURCES Obrttg SOURCES)
foreach (source_j ${OBRTTG_SOURCES})
    message(STATUS "${source_j}")
endforeach()