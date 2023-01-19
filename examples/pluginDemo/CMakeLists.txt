cmake_minimum_required(VERSION 3.24)
project(pluginDemo)

set(CMAKE_CXX_STANDARD 11)

add_library(pluginDemo SHARED library.cpp)
