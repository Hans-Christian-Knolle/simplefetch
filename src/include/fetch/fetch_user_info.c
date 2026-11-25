#include "fetch.h"

USERInfo fetchUSERInfo(void) {
    USERInfo user_info = {
        .username = "hck",
        .home_directory = "/home/hck",
        .hostname = "elitebook435"
    };
    return user_info;
}
