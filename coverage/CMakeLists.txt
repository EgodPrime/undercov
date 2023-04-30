project(undercov)

add_link_options(-lrt)

add_library(undercov_trace SHARED undercov_trace.cc)
add_library(undercov_info SHARED undercov_info.cc)

add_library(lib:undercov_trace ALIAS undercov_trace)
add_library(lib:undercov_info ALIAS undercov_info)

install(TARGETS undercov_trace undercov_info LIBRARY DESTINATION /usr/lib)