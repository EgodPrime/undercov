project(undercov_ins)

execute_process(
  COMMAND ${CMAKE_CXX_COMPILER} -print-file-name=plugin
  OUTPUT_VARIABLE GCC_PLUGIN_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

include_directories(${GCC_PLUGIN_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/extern_libs/include)

add_executable(undercov_ins_server undercov_ins_server.cc)

add_library(${PROJECT_NAME} SHARED undercov_ins.cc)

target_compile_options(${PROJECT_NAME} 
  PUBLIC -fno-rtti 
  PUBLIC -Wno-literal-suffix)

target_link_libraries(${PROJECT_NAME} lib:murmurhash)

add_library(lib:undercov_ins ALIAS ${PROJECT_NAME})

get_target_property(PLUGIN_DIR ${PROJECT_NAME} LIBRARY_OUTPUT_DIRECTORY)

set(PLUGIN_SO ${PLUGIN_DIR}/lib${PROJECT_NAME}.so CACHE STRING "Path of the plugin")

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION /usr/lib)