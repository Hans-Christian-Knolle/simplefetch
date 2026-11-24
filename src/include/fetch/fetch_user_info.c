#include "fetch.h"

USERInfo fetchUSERInfo(void) {
    USERInfo user_info = {
        .username = "hck",
        .uid = 1341131412,
        .home_directory = "/home/hck",
        .hostname = "elitebook435",
        .gid = 31151321412
    };
    return user_info;
}
