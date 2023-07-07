cmake_minimum_required(VERSION 3.8)

project(trunc_pyramid_lib LANGUAGES CXX)

set(FILES TruncatedPyramid.cpp TruncatedPyramid.hpp)

include_directories(../3DGeometry)

add_library(trunc_pyramid_lib STATIC ${FILES})