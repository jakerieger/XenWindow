#pragma once

#define CAST_ALIASES
#include <Types/Types.h>

namespace Xen {
    class INativeWindow {
    public:
        virtual ~INativeWindow()                = default;
        virtual void show()                     = 0;
        virtual void update()                   = 0;
        virtual void close()                    = 0;
        virtual void minimize()                 = 0;
        virtual void toggleMaximize()           = 0;
        virtual void setTitle(const str& title) = 0;
    };
}  // namespace Xen
