set(LIB_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
file(GLOB_RECURSE SOURCE_FILES "${LIB_ROOT_DIR}/source/*.cpp")

add_library(${TARGET_LIB} STATIC)

target_sources(${TARGET_LIB} PUBLIC ${SOURCE_FILES})
target_include_directories(${TARGET_LIB} PUBLIC "${LIB_ROOT_DIR}/include")
