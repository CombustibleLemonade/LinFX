cmake_minimum_required(VERSION 2.6)

project(LinFX)

add_definitions(-std=c++11)

add_executable(run main.cpp)
target_link_libraries(run ${CMAKE_DL_LIBS})

add_library(LinFX SHARED library.cpp)
configure_file(run.sh run.sh COPYONLY)
