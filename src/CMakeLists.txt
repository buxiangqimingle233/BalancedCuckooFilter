aux_source_directory (. SRC_LIST)
set (ROOT_DIR ${PROJECT_SOURCE_DIR})
message(${ROOT_DIR})
include_directories (${ROOT_DIR}/include)


add_executable(cuckoo_filter main.cpp collect.cpp cuckoo_filter.cpp)
target_link_libraries (cuckoo_filter ${ROOT_DIR}/lib/libxxhash.a)

set (EXECUTABLE_OUTPUT_PATH ${ROOT_DIR}/bin)