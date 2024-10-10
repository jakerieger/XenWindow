#pragma once

#include <XenWindow/NativeWindow.h>

namespace Xen {
    class WaylandWindow : public INativeWindow {
    public:
        WaylandWindow(const str& title, int width, int height);

        void show() override;
        void update() override;
        void close() override;
        void minimize() override;
        void toggleMaximize() override;
        void setTitle(const str& title) override;

    private:
        str title;
        int width;
        int height;
        bool maximized = false;
    };
}  // namespace Xen
