cmake_minimum_required(VERSION 3.8)

project(parallelepiped_lib LANGUAGES CXX)

set(FILES Parallelepiped.cpp Parallelepiped.hpp)

include_directories(../3DGeometry)

add_library(parallelepiped_lib STATIC ${FILES})