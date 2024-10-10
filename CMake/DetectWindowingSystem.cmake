if (WIN32)
  set(WINDOWING_SYSTEM "Windows")
elseif(UNIX AND NOT APPLE)
      add_definitions(-DPLATFORM_LINUX)
    # Check for X11
    find_package(X11 QUIET)
    if (X11_FOUND)
        message(STATUS "X11 libraries found")
    else ()
        message(STATUS "X11 libraries not found")
    endif ()

    # Check for Wayland
    find_package(PkgConfig)
    pkg_check_modules(WAYLAND_CLIENT QUIET wayland-client)

    if (WAYLAND_CLIENT_FOUND)
        message(STATUS "Wayland libraries found")
    else ()
        message(STATUS "Wayland libraries not found")
    endif ()

    # Determine the active windowing system and set preprocessor defines
    if (DEFINED ENV{WAYLAND_DISPLAY})
        message(STATUS "Wayland is the active windowing system")
        add_definitions(-DUSE_WAYLAND)
        set(WINDOWING_SYSTEM "Wayland")

        pkg_check_modules(WAYLAND_EGL REQUIRED wayland-egl)
        pkg_check_modules(WAYLAND_PROTO REQUIRED wayland-protocols)
        pkg_check_modules(EGL REQUIRED egl)
        # target_link_libraries(Fuse PRIVATE wayland-client wayland-egl wayland-protocols egl)
    elseif (DEFINED ENV{DISPLAY})
        message(STATUS "X11 is the active windowing system")
        add_definitions(-DUSE_X11)
        set(WINDOWING_SYSTEM "X11")

      
        # target_link_libraries(Fuse PRIVATE X11)
    else ()
        message(STATUS "No active windowing system detected")
    endif ()

    # Link Cairo for all linux platforms
elseif (APPLE)
  set(WINDOWING_SYSTEM "Apple")
endif()
