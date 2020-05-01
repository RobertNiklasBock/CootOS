#pragma once
#define NASP(name) coot_raspi_atags__##name

#include "raspi/atags/Atag.h"
#include "raspi/atags/TAGID.h"

uint32_t coot_raspi_atags__get_mem_size(coot_raspi_atags__Atag_t* atags);

#undef NASP


