cmake_minimum_required(VERSION 3.8)

project(geometric_data LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(3DGeometry)
add_subdirectory(Cube)

include_directories(3DGeometry Cube)

add_executable(geometric_data main.cpp)

target_link_libraries(geometric_data geometry_lib cube_lib)

file(COPY ${CMAKE_SOURCE_DIR}/test_data
        DESTINATION ${CMAKE_SOURCE_DIR}/bin/)


