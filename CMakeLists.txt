cmake_minimum_required(VERSION 3.8)

project(geometric_data LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(3DGeometry)
add_subdirectory(Cube)
add_subdirectory(Parallelepiped)
add_subdirectory(Pyramid)
add_subdirectory(TruncatedPyramid)
add_subdirectory(Prism)

include_directories(3DGeometry Cube Parallelepiped Pyramid TruncatedPyramid Prism)

add_executable(geometric_data main.cpp )

target_link_libraries(geometric_data geometry_lib cube_lib parallelepiped_lib pyramid_lib trunc_pyramid_lib prism_lib)

file(COPY ${CMAKE_SOURCE_DIR}/test_data
        DESTINATION ${CMAKE_SOURCE_DIR}/bin/)


