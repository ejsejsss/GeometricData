cmake_minimum_required(VERSION 3.8)

project(prism_lib LANGUAGES CXX)

set(FILES Prism.cpp Prism.hpp)

include_directories(../3DGeometry)

add_library(prism_lib STATIC ${FILES})