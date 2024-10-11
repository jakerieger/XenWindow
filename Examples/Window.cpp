#define INC_FUNCTION
#include <XenWindow/XenWindow.h>

int main() {
    auto window = Xen::CreateWindow("My Window", 800, 600);
    window->show();

    static bool running = true;
    while (running) {
        window->update();
    }
    window->close();

    return 0;
}
