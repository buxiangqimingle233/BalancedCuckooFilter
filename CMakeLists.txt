cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}")

project (cuckoo)

add_subdirectory (src)