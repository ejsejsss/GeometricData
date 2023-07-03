cmake_minimum_required (VERSION 3.8)

project(geometric_data LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(3DGeometry)

include_directories(3DGeometry )

add_executable(geometric_data main.cpp)

target_link_libraries(geometric_data geometry_lib)

