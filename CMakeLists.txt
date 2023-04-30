cmake_minimum_required(VERSION 3.16)

set(GCC_DIR /root/gcc_install)
set(CMAKE_C_COMPILER ${GCC_DIR}/bin/gcc)
set(CMAKE_CXX_COMPILER ${GCC_DIR}/bin/g++)

project(undercov VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_compile_options(-std=c++17 -Wall -O3 -fPIC)

# add_definitions(-DDMC_DEBUG)

add_subdirectory(extern_libs)
add_subdirectory(instrument)
add_subdirectory(coverage)
add_subdirectory(test)

install(DIRECTORY include/ DESTINATION /usr/include)