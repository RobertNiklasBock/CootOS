#include "io/uart0.h"
#include "registers.h"

/**
 * Set baud rate and characteristics (115200 8N1) and map to GPIO
 */
void coot_uart0__init(void)
{
    /* initialize UART */
    *UART0_CR = 0;         // turn off UART0

    /* set up clock for consistent divisor values */
    // mbox[0] = 9*4;
    // mbox[1] = MBOX_REQUEST;
    // mbox[2] = MBOX_TAG_SETCLKRATE; // set clock rate
    // mbox[3] = 12;
    // mbox[4] = 8;
    // mbox[5] = 2;           // UART clock
    // mbox[6] = 4000000;     // 4Mhz
    // mbox[7] = 0;           // clear turbo
    // mbox[8] = MBOX_TAG_LAST;
    // mbox_call(MBOX_CH_PROP);

    /* map UART0 to GPIO pins */
    uint32_t r = *GPFSEL1;
    r&=~((7<<12)|(7<<15)); // gpio14, gpio15
    r|=(4<<12)|(4<<15);    // alt0
    *GPFSEL1 = r;
    *GPPUD = 0;            // enable pins 14 and 15
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = (1<<14)|(1<<15);
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = 0;        // flush GPIO setup

    *UART0_ICR = 0x7FF;    // clear interrupts
    *UART0_IBRD = 2;       // 115200 baud
    *UART0_FBRD = 0xB;
    *UART0_LCRH = 0b11<<5; // 8n1
    *UART0_CR = 0x301;     // enable Tx, Rx, FIFO
}

/**
 * Send a character
 */
void coot_uart0__putc(byte_t c) {
    /* wait until we can putc */
    do{asm volatile("nop");}while(!(*AUX_MU_LSR&0x20));
    /* write the character to the buffer */
    *AUX_MU_IO=c;
}

/**
 * Receive a character
 */
char coot_uart0__getc(void) {
    char r;
    /* wait until something is in the buffer */
    do{asm volatile("nop");}while(!(*AUX_MU_LSR&0x01));
    /* read it and return */
    r=(char)(*AUX_MU_IO);
    /* convert carrige return to newline */
    return r=='\r'?'\n':r;
}

/**
 * Display a string
 */
void coot_uart0__puts(char *s) {
    while(*s) {
        /* convert newline to carrige return + newline */
        if(*s=='\n')
            coot_uart0__putc('\r');
        coot_uart0__putc(*s++);
    }
}

/**
 * Display a binary value in hexadecimal
 */
void coot_uart0__putx(uint32_t d) {
    for(int c=28; c>=0; c-=4) {
        char n = (d >> c) & 0x0F;
        n += (n > 9) ? 0x37 : 0x30;
        coot_uart0__putc(n);
    }
}
