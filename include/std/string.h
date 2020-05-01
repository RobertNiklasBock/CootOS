#pragma once
#include "std/inttypes.h"

const char* coot_string__base_alphabet[16];

char* coot_string__itoa(int32_t value, char* str, uint8_t base);
char* coot_string__reverse(char* str);
char* coot_string__reverse_l(char* str, uint32_t length);