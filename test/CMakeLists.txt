project(undercov_test)

set_directory_properties(PROPERTIES COMPILE_OPTIONS "")

add_compile_options(-fplugin=${PLUGIN_SO})

add_link_options(-lrt)

add_executable(undercov_test test.cc)

target_link_libraries(undercov_test lib:undercov_trace)

configure_file(coverage.py ${CMAKE_BINARY_DIR}/test/coverage.py COPYONLY)

add_executable(test_undercov_info test_undercov_info.cc)

target_link_libraries(test_undercov_info lib:undercov_info)

