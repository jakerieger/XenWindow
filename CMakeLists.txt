cmake_minimum_required(VERSION 3.14)
project(XenWindow LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)
set(INCDIR ${CMAKE_CURRENT_SOURCE_DIR}/Include)
set(THIRDPARTY ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/DetectWindowingSystem.cmake)

include_directories(
  ${SRCDIR}
  ${INCDIR}
  ${THIRDPARTY}
)

set(LIB_INCLUDES
  ${INCDIR}/XenWindow/XenWindow.h
  ${INCDIR}/XenWindow/NativeWindow.h
  ${INCDIR}/XenWindow/WaylandWindow.h 
)

set(LIB_SOURCES
  ${SRCDIR}/XenWindow.cpp
  ${SRCDIR}/WaylandWindow.cpp
)

add_library(XenWindow STATIC
  ${LIB_INCLUDES}
  ${LIB_SOURCES}
)

# EXAMPLES
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Examples)

