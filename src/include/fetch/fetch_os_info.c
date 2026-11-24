#include "fetch.h"

OSInfo fetchOSInfo(void) {
    OSInfo os_info = {
        .name = "Void Linux",
        .kernel = "Linux 6.18.64_1",
        .architecture = "x86_64",
        .version = "glibc",
        .window_manager = "Muffin (X11)",
        .desktop_environment = "Cinnamon 6.6.7"
    };
    return os_info;
}
