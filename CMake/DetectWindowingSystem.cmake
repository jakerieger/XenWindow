if (WIN32)
  set(WINDOWING_SYSTEM "Windows")
elseif(UNIX AND NOT APPLE)
      add_definitions(-DPLATFORM_LINUX)
    # Check for X11
    find_package(X11 QUIET)
    find_package(PkgConfig)
    pkg_check_modules(WAYLAND_CLIENT QUIET wayland-client)

    # Determine the active windowing system and set preprocessor defines
    if (DEFINED ENV{WAYLAND_DISPLAY})
        set(WINDOWING_SYSTEM "Wayland")

        pkg_check_modules(WAYLAND_EGL REQUIRED wayland-egl)
        pkg_check_modules(WAYLAND_PROTO REQUIRED wayland-protocols)
        pkg_check_modules(EGL REQUIRED egl)
        # target_link_libraries(Fuse PRIVATE wayland-client wayland-egl wayland-protocols egl)
    elseif (DEFINED ENV{DISPLAY})
        set(WINDOWING_SYSTEM "X11")

      
        # target_link_libraries(Fuse PRIVATE X11)
    else ()
        message(STATUS "No active windowing system detected")
    endif ()
elseif (APPLE)
    set(WINDOWING_SYSTEM "Apple")
else()
    message(STATUS "No active or supported windowing system was detected.")
endif()
