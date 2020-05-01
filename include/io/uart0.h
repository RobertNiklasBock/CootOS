#pragma once
#include "std/inttypes.h"
#include "registers.h"
#include "raspi/mailbox.h"

#define UART0_DR   ((volatile uint32_t*)(MMIO_BASE+0x00201000))
#define UART0_FR   ((volatile uint32_t*)(MMIO_BASE+0x00201018))
#define UART0_IBRD ((volatile uint32_t*)(MMIO_BASE+0x00201024))
#define UART0_FBRD ((volatile uint32_t*)(MMIO_BASE+0x00201028))
#define UART0_LCRH ((volatile uint32_t*)(MMIO_BASE+0x0020102C))
#define UART0_CR   ((volatile uint32_t*)(MMIO_BASE+0x00201030))
#define UART0_IMSC ((volatile uint32_t*)(MMIO_BASE+0x00201038))
#define UART0_ICR  ((volatile uint32_t*)(MMIO_BASE+0x00201044))


