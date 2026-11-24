#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "arguments.h"
#include "config.h"
#include "fetch/fetch.h"
#include "info.h"

// This is the config. The programm need to be recompiled if config is changed
// I am not into json libraries yet. Probably will implement that later
static const Order order[] = {
    USER_INFO,
    OS_INFO,
    ENV_INFO,
    CPU_INFO,
    GPU_INFO,
    MEM_INFO
};

static const Config config = {
    .order = order,
    .show_user_info = true,
    .show_os_info = true,
    .show_env_info = true,
    .show_cpu_info = true,
    .show_gpu_info = true,
    .show_mem_info = true
};

int main(int argc, char *argv[]) {
    // Handle arguments
    if (argc == 2) {
        // --help (-h) is the only valid argument
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            show_help_message();
            return EXIT_SUCCESS;
        }
    // TODO: Add --all argument that overrides the config on top
    } else if (argc > 2) {
        fprintf(stderr, "Too many arguments!\n");
        return EXIT_FAILURE;
    }

    Info info = {
        .user_info = fetchUSERInfo(),
        .os_info = fetchOSInfo(),
        .env_info = fetchENVInfo(),
        .cpu_info = fetchCPUInfo(),
        .gpu_info = fetchGPUInfo(),
        .mem_info = fetchMEMInfo()
    };

    return show_info(&info, &config);
}
