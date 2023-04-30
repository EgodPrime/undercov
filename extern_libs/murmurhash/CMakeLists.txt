project(murmurhash)

include_directories(${CMAKE_SOURCE_DIR}/extern_libs/include)

add_library(${PROJECT_NAME} OBJECT MurmurHash3.cc)
add_library(lib:murmurhash ALIAS ${PROJECT_NAME})