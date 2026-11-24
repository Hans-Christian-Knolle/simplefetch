#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "info.h"
#include "config.h"

uint8_t show_info(const Info *info, const Config *config) {
    for (int i = 0; i < 6; i++) {
        switch (config->order[i]) {
            case USER_INFO:
                continue;
            case ENV_INFO:
                continue;
            case OS_INFO:
                continue;
            case CPU_INFO:
                if (config->show_cpu_info) {
                    printf("CPU: %s %s (%i/%i) @ %.2f GHz (%s)\n",
                        info->cpu_info.vendor,
                        info->cpu_info.model,
                        info->cpu_info.cores,
                        info->cpu_info.threads,
                        info->cpu_info.frequency_ghz,
                        info->cpu_info.architecture
                    );
                }
                continue;
            case GPU_INFO:
                continue;
            case MEM_INFO:
                continue;
        }
    }

    return EXIT_SUCCESS;
}
