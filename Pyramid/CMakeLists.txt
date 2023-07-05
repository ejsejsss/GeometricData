cmake_minimum_required(VERSION 3.8)

project(pyramid_lib LANGUAGES CXX)

set(FILES Pyramid.cpp Pyramid.hpp)

include_directories(../3DGeometry)

add_library(pyramid_lib STATIC ${FILES})