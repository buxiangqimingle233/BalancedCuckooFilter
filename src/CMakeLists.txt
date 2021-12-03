aux_source_directory (. SRC_LIST)
set (ROOT_DIR ${CMAKE_BINARY_DIR})

set(sources main.cpp collect.cpp cuckoo_filter.cpp)
add_executable(cuckoo_filter ${sources})
target_include_directories(cuckoo_filter PUBLIC ${CMAKE_BINARY_DIR}/include)
target_link_libraries (cuckoo_filter ${ROOT_DIR}/lib/libxxhash.a cityhash)
