cmake_minimum_required(VERSION 2.8)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})


add_library(LinFX SHARED glClearInjection.cpp hooker.cpp)
