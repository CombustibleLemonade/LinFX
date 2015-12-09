cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core REQUIRED)
qt5_add_resources(QT_RESOURCE ../resources/shaders.qrc)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIRS})

add_library(LinFX SHARED  hooker.cpp OpenGLhelpers/object3d.cpp OpenGLhelpers/effect.cpp OpenGLhelpers/print.cpp)
target_link_libraries(LinFX GL GLU Qt5::Core)
