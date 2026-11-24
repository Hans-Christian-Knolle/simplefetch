#include "fetch.h"

GPUInfo fetchGPUInfo(void) {
    GPUInfo gpu_info = {
        .vendor = "AMD",
        .model = "Radeon RX Vega 7",
        .architecture = "AMD VEGA Renoir",
        .driver = "RADV Mesa 26.1",
        .vram_total_mb = 512,
        .vram_used_mb = 413
    };
    return gpu_info;
}
