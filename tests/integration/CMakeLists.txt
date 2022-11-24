set(TARGET_TEST "${TARGET_LIB}Integration")
set(TEST_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE SOURCE_FILES "${TEST_ROOT_DIR}/source/*.cpp")

# Find GTest and pthread libraries
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# Include GTest headers
include_directories(${GTEST_INCLUDE_DIRS})
include_directories("${TEST_ROOT_DIR}/include")
 
add_executable(${TARGET_TEST})
target_sources(${TARGET_TEST} PUBLIC ${SOURCE_FILES})
target_link_libraries(${TARGET_TEST} ${GTEST_LIBRARIES} pthread)
target_link_libraries(${TARGET_TEST} ${TARGET_LIB})
