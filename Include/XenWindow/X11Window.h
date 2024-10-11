#pragma once

#include <XenWindow/NativeWindow.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

namespace Xen {
    class X11Window : public INativeWindow {
    public:
        X11Window(const str& title, int width, int height) noexcept;
        ~X11Window();

        void update() override;
        void show() override;
        void close() override;
        void minimize() override;
        void toggleMaximize() override;
        void setTitle(const str& title) override;

    private:
        Display* display;
        Window window;
        GC gc;
        XEvent ev;
        XImage* renderImage;
    };
}  // namespace Xen
