#include "time/sleep.h"

void busy_wait(uint64_t cycles) {
    while(cycles--) {
        asm volatile("nop");
    }
}

void wait_until(uint8_t cond_call) {
    while(!cond_call) {
        asm volatile("nop");
    } 
}
