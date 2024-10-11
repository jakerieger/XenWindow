#pragma once

#include <memory>
#define CAST_ALIASES
#define PTR_ALIASES
#include <Types/Types.h>

#if defined(_WS_WINDOWS)
    #include <XenWindow/Win32Window.h>
using ActiveWindow = Xen::Win32Window;
#elif defined(_WS_X11)
    #include <XenWindow/X11Window.h>
using ActiveWindow = Xen::X11Window;
#elif defined(_WS_WAYLAND)
    #include <XenWindow/WaylandWindow.h>
using ActiveWindow = Xen::WaylandWindow;
#elif defined(_WS_APPLE)
    #include <XenWindow/AppleWindow.h>
using ActiveWindow = Xen::AppleWindow;
#else
std::cerr << "Unsupported platform." << std::endl;
std::abort();
#endif

namespace Xen {
    static Shared<INativeWindow>
    CreateWindow(const str& title, int width, int height) {
        return std::make_shared<ActiveWindow>(title, width, height);
    }
}  // namespace Xen
