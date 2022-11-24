cmake_minimum_required(VERSION 3.22)

project(AOCPP)

set(TARGET_LIB LibCAOCPP)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/output/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/output/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/output/bin")

include_directories("lib/include")

add_subdirectory("lib")
add_subdirectory("tests")