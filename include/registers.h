#pragma once
#include "std/inttypes.h"

#define MMIO_BASE       0x3F000000

#pragma region GPIO
    #define GPFSEL0         ((volatile uint32_t*)(MMIO_BASE+0x00200000))
    #define GPFSEL1         ((volatile uint32_t*)(MMIO_BASE+0x00200004))
    #define GPFSEL2         ((volatile uint32_t*)(MMIO_BASE+0x00200008))
    #define GPFSEL3         ((volatile uint32_t*)(MMIO_BASE+0x0020000C))
    #define GPFSEL4         ((volatile uint32_t*)(MMIO_BASE+0x00200010))
    #define GPFSEL5         ((volatile uint32_t*)(MMIO_BASE+0x00200014))
    #define GPSET0          ((volatile uint32_t*)(MMIO_BASE+0x0020001C))
    #define GPSET1          ((volatile uint32_t*)(MMIO_BASE+0x00200020))
    #define GPCLR0          ((volatile uint32_t*)(MMIO_BASE+0x00200028))
    #define GPLEV0          ((volatile uint32_t*)(MMIO_BASE+0x00200034))
    #define GPLEV1          ((volatile uint32_t*)(MMIO_BASE+0x00200038))
    #define GPEDS0          ((volatile uint32_t*)(MMIO_BASE+0x00200040))
    #define GPEDS1          ((volatile uint32_t*)(MMIO_BASE+0x00200044))
    #define GPHEN0          ((volatile uint32_t*)(MMIO_BASE+0x00200064))
    #define GPHEN1          ((volatile uint32_t*)(MMIO_BASE+0x00200068))
    #define GPPUD           ((volatile uint32_t*)(MMIO_BASE+0x00200094))
    #define GPPUDCLK0       ((volatile uint32_t*)(MMIO_BASE+0x00200098))
    #define GPPUDCLK1       ((volatile uint32_t*)(MMIO_BASE+0x0020009C))
#pragma endregion // GPIO

#pragma region UART1
    #define AUX_ENABLE          ((volatile uint32_t*)(MMIO_BASE+0x00215004))
    #define AUX_MU_IO           ((volatile uint32_t*)(MMIO_BASE+0x00215040))
    #define AUX_MU_IER          ((volatile uint32_t*)(MMIO_BASE+0x00215044))
    #define AUX_MU_IIR          ((volatile uint32_t*)(MMIO_BASE+0x00215048))
    #define AUX_MU_LCR          ((volatile uint32_t*)(MMIO_BASE+0x0021504C))
    #define AUX_MU_MCR          ((volatile uint32_t*)(MMIO_BASE+0x00215050))
    #define AUX_MU_LSR          ((volatile uint32_t*)(MMIO_BASE+0x00215054))
    #define AUX_MU_MSR          ((volatile uint32_t*)(MMIO_BASE+0x00215058))
    #define AUX_MU_SCRATCH      ((volatile uint32_t*)(MMIO_BASE+0x0021505C))
    #define AUX_MU_CNTL         ((volatile uint32_t*)(MMIO_BASE+0x00215060))
    #define AUX_MU_STAT         ((volatile uint32_t*)(MMIO_BASE+0x00215064))
    #define AUX_MU_BAUD         ((volatile uint32_t*)(MMIO_BASE+0x00215068))
#pragma endregion // UART1

#pragma region UART0
    #define UART0_DR        ((volatile unsigned int*)(MMIO_BASE+0x00201000))
    #define UART0_FR        ((volatile unsigned int*)(MMIO_BASE+0x00201018))
    #define UART0_IBRD      ((volatile unsigned int*)(MMIO_BASE+0x00201024))
    #define UART0_FBRD      ((volatile unsigned int*)(MMIO_BASE+0x00201028))
    #define UART0_LCRH      ((volatile unsigned int*)(MMIO_BASE+0x0020102C))
    #define UART0_CR        ((volatile unsigned int*)(MMIO_BASE+0x00201030))
    #define UART0_IMSC      ((volatile unsigned int*)(MMIO_BASE+0x00201038))
    #define UART0_ICR       ((volatile unsigned int*)(MMIO_BASE+0x00201044))
#pragma endregion // UART0

#pragma region RAND
    #define RNG_CTRL        ((volatile unsigned int*)(MMIO_BASE+0x00104000))
    #define RNG_STATUS      ((volatile unsigned int*)(MMIO_BASE+0x00104004))
    #define RNG_DATA        ((volatile unsigned int*)(MMIO_BASE+0x00104008))
    #define RNG_INT_MASK    ((volatile unsigned int*)(MMIO_BASE+0x00104010))
#pragma endregion // RAND
