#pragma once
#define NASP(name) coot_raspi_mailbox__##name

#include <std/inttypes.h>
#include "raspi/mailbox/REQRESCODE.h"

typedef struct {
    uint32_t size;                      // Size includes the size itself
    uint32_t req_res_code;
    uint32_t tags[1];                    // A concatenated sequence of tags. will use overrun to make large enough
} coot_raspi_mailbox__MessageBuffer_t;

#undef NASP
