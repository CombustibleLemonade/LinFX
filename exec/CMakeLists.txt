cmake_minimum_required(VERSION 2.8.12)

add_executable(proceduralHeader parse.cpp)
target_link_libraries(proceduralHeader ${CMAKE_DL_LIBS})

#add_custom_target(runner ALL DEPENDS headerfile)

#add_custom_command(
#  OUTPUT headerfile
#  COMMAND proceduralHeader
#  ARGS ${PROJECT_SOURCE_DIR}/source
#  POST_BUILD)
