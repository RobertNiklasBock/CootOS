#pragma once
#define NASP(name) coot__std__##name

#include "inttypes.h"
#include "registers.h"

void NASP(init)();

uint32_t NASP(randint)(uint32_t min, uint32_t max);


#undef NASP

