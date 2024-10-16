cmake_minimum_required(VERSION 3.24)

project(am_vis VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${CMAKE_CURRENT_BINARY_DIR}/libs/sqlite
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/sqlite)

add_subdirectory("src")
add_subdirectory("libs/sqlite")

target_link_libraries(main sqlite)
