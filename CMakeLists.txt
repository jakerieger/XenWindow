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
)

set(LIB_SOURCES
  ${SRCDIR}/XenWindow.cpp
  ${SRCDIR}/Panic.inl
)

add_library(XenWindow STATIC
  ${LIB_INCLUDES}
  ${LIB_SOURCES}
)

# Handle platform-specific sources 
if (WINDOWING_SYSTEM STREQUAL "Windows")
    add_definitions(-D_WS_WINDOWS)

    target_sources(XenWindow PRIVATE
        ${INCDIR}/XenWindow/Win32Window.h 
        ${SRCDIR}/Win32Window.cpp
    )
elseif(WINDOWING_SYSTEM STREQUAL "X11")
    add_definitions(-D_WS_X11)

    target_sources(XenWindow PRIVATE
        ${INCDIR}/XenWindow/X11Window.h 
        ${SRCDIR}/X11Window.cpp
    )

    target_link_libraries(XenWindow PRIVATE X11)
elseif (WINDOWING_SYSTEM STREQUAL "Wayland")
    add_definitions(-D_WS_WAYLAND)

    target_sources(XenWindow PRIVATE
        ${INCDIR}/XenWindow/WaylandWindow.h 
        ${SRCDIR}/WaylandWindow.cpp
    )

    target_link_libraries(XenWindow PRIVATE
        wayland-client
        wayland-egl
        wayland-protocols
        egl
    )
elseif (WINDOWING_SYSTEM STREQUAL "Apple")
    add_definitions(_D_WS_APPLE)

    target_sources(XenWindow PRIVATE
        ${INCDIR}/XenWindow/AppleWindow.h 
        ${SRCDIR}/AppleWindow.cpp
    )
endif()

# EXAMPLES
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Examples)

