cmake_minimum_required(VERSION 3.15)
project(cpp_through_game_programming)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/runtime")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(hello_world)
add_subdirectory(
    chapter_1
)