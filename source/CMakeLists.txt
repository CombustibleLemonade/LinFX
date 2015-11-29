cmake_minimum_required(VERSION 2.8)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIRS})

add_library(LinFX SHARED glClearInjection.cpp hooker.cpp OpenGLhelpers/object3d.cpp)
target_link_libraries(LinFX GL GLU)
