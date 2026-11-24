#include "fetch.h"

MEMInfo fetchMEMInfo(void) {
    MEMInfo mem_info = {
        .total_mb = 16384,
        .free_mb = 14312,
        .used_mb = 2072,
        .usage_percentage = 7.9
    };
    return mem_info;
}
