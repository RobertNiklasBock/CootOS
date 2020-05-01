#pragma once
#include "std/inttypes.h"

void coot_uart1__init();
void coot_uart1__putc(char);
char coot_uart1__getc();
void coot_uart1__puts(char *s);
void coot_uart1__putx(uint32_t d);