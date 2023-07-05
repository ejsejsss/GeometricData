cmake_minimum_required(VERSION 3.8)

project(geometry_lib LANGUAGES CXX)

set(FILES IArea.hpp IVolume.hpp object3d.hpp vertex.hpp vertex.cpp)

add_library(geometry_lib STATIC ${FILES})
