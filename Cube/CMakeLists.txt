cmake_minimum_required(VERSION 3.8)

project(cube_lib LANGUAGES CXX)

set(FILES cube.hpp cube.cpp)

include_directories(../3DGeometry)

add_library(cube_lib STATIC ${FILES})