#include <XenWindow/WaylandWindow.h>

namespace Xen {
    WaylandWindow::WaylandWindow(const str& title, int width, int height) {
        this->title  = title;
        this->width  = width;
        this->height = height;
    }

    void WaylandWindow::show() {}

    void WaylandWindow::update() {}

    void WaylandWindow::close() {}

    void WaylandWindow::minimize() {}

    void WaylandWindow::toggleMaximize() {}

    void WaylandWindow::setTitle(const str& title) {}
}  // namespace Xen
