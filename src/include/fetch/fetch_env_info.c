#include "fetch.h"

ENVInfo fetchENVInfo(void) {
    ENVInfo env_info = {
        .shell = "bash 5.3.0",
        .terminal = "kitty",
        .package_count = 915,
        .uptime = "4:35"
    };
    return env_info;
}
