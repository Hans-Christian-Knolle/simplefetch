#include "fetch.h"

CPUInfo fetchCPUInfo(void) {
    CPUInfo cpu_info = {
        .vendor = "AMD",
        .model = "Ryzen 7 PRO 4750U",
        .architecture = "AMD64",
        .cores = 8,
        .threads = 16,
        .frequency_ghz = 1.70
    };
    return cpu_info;
}
