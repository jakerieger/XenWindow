cmake_minimum_required(VERSION 3.14)
project(XenWindow)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Examples)
set(EXDIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Window ${EXDIR}/Window.cpp)
target_link_libraries(Window PRIVATE XenWindow)
