#pragma once

#define CAST_ALIASES
#define INC_FUNCTION
#include <Types/Types.h>

namespace Xen {
    class INativeWindow {
    public:
        INativeWindow(const str& title, int width, int height)
            : title(title), width(width), height(height) {}
        virtual ~INativeWindow()                = default;
        virtual void show()                     = 0;
        virtual void update()                   = 0;
        virtual void close()                    = 0;
        virtual void minimize()                 = 0;
        virtual void toggleMaximize()           = 0;
        virtual void setTitle(const str& title) = 0;

        str title;
        int width;
        int height;
    };
}  // namespace Xen
