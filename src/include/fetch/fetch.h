#ifndef FETCH_H
#define FETCH_H

#include <sys/types.h>

// Return types that contain the fetched info
typedef struct
{
    const char *vendor;
    const char *model;
    const char *architecture;

    uint cores;
    uint threads;
    double frequency_ghz;
} CPUInfo;

typedef struct
{
    const char *vendor;
    const char *model;
    const char *driver;
    const char *architecture;

    ulong vram_total_mb;
    ulong vram_used_mb;
} GPUInfo;

typedef struct
{
    ulong total_mb;
    ulong used_mb;
    ulong free_mb;
    double usage_percentage;
} MEMInfo;

typedef struct
{
    const char *name;
    const char *version;
    const char *kernel;
    const char *architecture;
    const char *desktop_environment;
    const char *window_manager;
} OSInfo;

typedef struct
{
    const char *shell;
    const char *terminal;
    const char *uptime;

    uint package_count;
} ENVInfo;

typedef struct
{
    const char *username;
    const char *hostname;
    const char *home_directory;

    uint uid;
    uint gid;
} USERInfo;

// Fetch functions
CPUInfo fetchCPUInfo(void);
GPUInfo fetchGPUInfo(void);
MEMInfo fetchMEMInfo(void);
OSInfo fetchOSInfo(void);
ENVInfo fetchENVInfo(void);
USERInfo fetchUSERInfo(void);

#endif
