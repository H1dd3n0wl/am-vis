include_directories(${CMAKE_CURRENT_SOURCE_DIR} 
                    ${CMAKE_CURRENT_SOURCE_DIR}/character
                    ${CMAKE_CURRENT_SOURCE_DIR}/DAO
                    ${CMAKE_CURRENT_SOURCE_DIR}/DAO/atanor
                    ${CMAKE_CURRENT_SOURCE_DIR}/entries/atanor
                    ${CMAKE_CURRENT_SOURCE_DIR}/entries/properties)

file(GLOB_RECURSE sources character/*.hpp 
                          character/*.cpp 
                          DAO/atanor/*.hpp 
                          DAO/atanor/*.cpp 
                          DAO/*.hpp 
                          entries/atanor/*.hpp
                          entries/atanor/*.cpp
                          entries/properties/*.hpp
                          entries/properties/*.cpp
                          tools/*.hpp)

                          
add_executable(main main.cpp ${sources})
target_compile_definitions(main PUBLIC ATANOR_ENTRIES_PATH="${CMAKE_SOURCE_DIR}/assets/atanor_entries/")
target_compile_definitions(main PUBLIC PSEUDONOR_ENTRIES_PATH="${CMAKE_SOURCE_DIR}/assets/pseudonor_entries/")