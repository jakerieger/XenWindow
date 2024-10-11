#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <XenWindow/X11Window.h>

#include "Panic.inl"

namespace Xen {
    X11Window::X11Window(const str& title, int width, int height) noexcept
        : INativeWindow(title, width, height) {
        display = XOpenDisplay(nullptr);
        if (!display) {
            Panic(__FILE__,
                  __LINE__,
                  __PRETTY_FUNCTION__,
                  "Failed to create X11 display.");
        }

        auto screen = DefaultScreen(display);
        window      = XCreateSimpleWindow(display,
                                     RootWindow(display, screen),
                                     0,
                                     0,
                                     this->width,
                                     this->height,
                                     1,
                                     BlackPixel(display, screen),
                                     WhitePixel(display, screen));
        XSelectInput(display, window, ExposureMask | KeyPressMask);
        XMapWindow(display, window);

        gc = XCreateGC(display, window, 0, nullptr);

        renderImage = XCreateImage(display,
                                   DefaultVisual(display, screen),
                                   24,
                                   ZPixmap,
                                   0,
                                   (char*)malloc(width * height * 4),
                                   width,
                                   height,
                                   32,
                                   0);
        if (!renderImage) {
            Panic(__FILE__,
                  __LINE__,
                  __PRETTY_FUNCTION__,
                  "Failed to create render image for X11 window.");
        }
    }

    X11Window::~X11Window() {
        XDestroyImage(renderImage);
        XFreeGC(display, gc);
        XDestroyWindow(display, window);
        XCloseDisplay(display);
    }

    void X11Window::update() {
        XNextEvent(display, &ev);

        if (ev.type == Expose) {
            // Copy the rendered UI image data to the window when exposed
        } else if (ev.type == KeyPress) {
            // Handle key press events
        }
    }

    void X11Window::show() {}

    void X11Window::close() {}

    void X11Window::minimize() {}

    void X11Window::toggleMaximize() {}

    void X11Window::setTitle(const str& title) {}
}  // namespace Xen
