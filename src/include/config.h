#ifndef CONFIG_H
#define CONFIG_H

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

/* Every number is mapped to a specific info:
 * 0: User info;
 * 1: Env info;
 * 2: OS info;
 * 3: CPU info;
 * 4: GPU info;
 * 5: Mem info
 */
typedef enum {
    USER_INFO =  0,
    ENV_INFO  =  1,
    OS_INFO   =  2,
    CPU_INFO  =  3,
    GPU_INFO  =  4,
    MEM_INFO  =  5
} Order;

typedef struct {
    const Order *order;

    bool show_user_info;
    bool show_env_info;
    bool show_os_info;
    bool show_cpu_info;
    bool show_gpu_info;
    bool show_mem_info;
} Config;

#endif
