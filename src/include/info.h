#ifndef SHOW_INFO_H
#define SHOW_INFO_H

#include <stddef.h>
#include <stdint.h>

#include "config.h"
#include "fetch/fetch.h"

// All fetched info in one struct
typedef struct {
    USERInfo user_info;
    ENVInfo env_info;
    OSInfo os_info;
    CPUInfo cpu_info;
    GPUInfo gpu_info;
    MEMInfo mem_info;
} Info;

uint8_t show_info(const Info *info, const Config *config, const size_t info_count);

#endif
