#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "info.h"
#include "config.h"

uint8_t show_info(const Info *info, const Config *config, const size_t info_count) {
    printf("%s@%s\n",
        info->user_info.username,
        info->user_info.hostname
    );
    printf("----------------\n\n");
    for (size_t i = 0; i < info_count; i++) {
        switch (config->order[i]) {
            case USER_INFO:
                if (config->show_user_info) {
                    printf("Home: %s\n", info->user_info.home_directory);
                }

                continue;
            case ENV_INFO:
                if (config->show_env_info) {
                    printf("Shell: %s\n", info->env_info.shell);
                    printf("Terminal: %s\n", info->env_info.terminal);
                    printf("Packages installed: %u\n", info->env_info.package_count);
                }
                continue;
            case OS_INFO:
                if (config->show_os_info) {
                    printf("OS: %s %s (%s)\n",
                        info->os_info.name,
                        info->os_info.version,
                        info->os_info.architecture
                    );
                    printf("Kernel: %s\n", info->os_info.kernel);
                    printf("Desktop: %s\n", info->os_info.desktop_environment);
                    printf("Window manager: %s\n", info->os_info.window_manager);
                }
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
                if (config->show_gpu_info) {
                    printf("GPU: %s %s %lu/%lu MiB (%s %s)\n",
                        info->gpu_info.vendor,
                        info->gpu_info.model,
                        info->gpu_info.vram_used_mb,
                        info->gpu_info.vram_total_mb,
                        info->gpu_info.architecture,
                        info->gpu_info.driver
                    );
                }
                continue;
            case MEM_INFO:
                if (config->show_mem_info) {
                    printf("Memory: %lu/%lu MiB (%.1f%% used, %lu MiB free)\n",
                        info->mem_info.used_mb,
                        info->mem_info.total_mb,
                        info->mem_info.usage_percentage,
                        info->mem_info.free_mb
                    );
                }
                continue;
        }
    }

    return EXIT_SUCCESS;
}
