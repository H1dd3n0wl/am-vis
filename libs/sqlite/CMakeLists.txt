file(GLOB_RECURSE sources *.c *.h)

add_library(sqlite ${sources})
target_include_directories(sqlite PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})