cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O3 ${CMAKE_CXX_FLAGS}")
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

project (cuckoo)

add_library(cityhash STATIC cityhash/src/city.cc)
set(cityhash_GEN ${CMAKE_BINARY_DIR}/cityhash)
configure_file(cityhash/config.h.in ${cityhash_GEN}/config.h)
target_include_directories(cityhash PUBLIC ${cityhash_GEN})
target_include_directories(cityhash PUBLIC cityhash/src)

add_subdirectory (src)