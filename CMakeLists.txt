cmake_minimum_required(VERSION 3.16)

# set the project name and version
project(EVB_MD VERSION 1.0)

# enable testing
include(cmake/tests.cmake)
include(cmake/run_simulation.cmake)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify the C++ compiler to be clang
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# add extra flags
string(CONCAT GCC_COVERAGE_COMPILE_FLAGS
       " -g"
       " -Werror"
       " -Wall"
       " -Wextra"
       " -Wpedantic"
       " -Wshadow"
       " -Wnon-virtual-dtor"
       " -Wold-style-cast"
       " -Wcast-align"
       " -Wunused"
       " -Woverloaded-virtual"
       " -Wconversion"
       " -Wsign-conversion"
       " -Wnull-dereference"
       " -Wdouble-promotion"
       " -Wformat=2"
       " -fsanitize=address "
       " -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# add sub directories
add_subdirectory(src)
