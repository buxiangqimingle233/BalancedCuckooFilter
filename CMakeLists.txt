cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O3 ${CMAKE_CXX_FLAGS}")
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
project (cuckoo)


# cityhash
add_library(cityhash STATIC cityhash/src/city.cc)
set(cityhash_dir ${CMAKE_BINARY_DIR}/cityhash)
configure_file(cityhash/config.h.in ${cityhash_dir}/config.h)
target_include_directories(cityhash PUBLIC ${cityhash_dir} ${cityhash_dir}/src)

# xxhash
file(GLOB static_libs lib/*.a)

# cuckoo filter
file(GLOB test_files src/*.cpp)
add_executable(cuckoo_filter ${test_files})
target_include_directories(cuckoo_filter PUBLIC ${CMAKE_BINARY_DIR}/include)
target_link_libraries (cuckoo_filter ${static_libs} cityhash)
