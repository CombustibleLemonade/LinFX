cmake_minimum_required(VERSION 2.6)

project(LinFX)

add_definitions(-std=c++11)

add_subdirectory(exec)
add_subdirectory(source)


include_directories(${Boost_INCLUDE_DIRS})
