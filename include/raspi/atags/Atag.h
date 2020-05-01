#pragma once
#define NASP(name) coot_raspi_atags__##name
#define CNASP(name) COOT_RASPI_ATAGS__##name

#include <std/inttypes.h>
#include "raspi/atags/TAGID.h"

typedef struct {
    uint32_t size;
    uint32_t start;
} coot_raspi_atags__MemBuffer_t;

typedef struct {
    uint32_t start;
    uint32_t size;
} coot_raspi_atags__InitRD2Buffer_t;

typedef struct {
    char line[1];
} coot_raspi_atags__CmdLineBuffer_t;

typedef struct {
    uint32_t tag_size;
    uint32_t id;
    union {
        coot_raspi_atags__MemBuffer_t mem;
        coot_raspi_atags__InitRD2Buffer_t initrd2;
        coot_raspi_atags__CmdLineBuffer_t cmdline;
    };
} coot_raspi_atags__Atag_t;

#undef NASP
