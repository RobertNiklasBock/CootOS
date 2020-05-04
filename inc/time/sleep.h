#pragma once
#include "std/inttypes.h"
#include "registers.h"

#define SYSTMR_LO        ((volatile unsigned int*)(MMIO_BASE+0x00003004))
#define SYSTMR_HI        ((volatile unsigned int*)(MMIO_BASE+0x00003008))

void busy_wait(uint64_t cycles);
void wait_until(uint8_t condition);