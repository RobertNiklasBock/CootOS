#include "io/uart1.h"
#include "registers.h"

/**
 * Set baud rate and characteristics (115200 8N1) and map to GPIO
 */
void coot_uart1__init(void)
{
    register uint32_t r;

    /* initialize UART */
    *AUX_ENABLE |= 0x01;       // enable UART1, AUX mini uart
    *AUX_MU_CNTL = 0;
    *AUX_MU_LCR = 3;       // 8 bits
    *AUX_MU_MCR = 0;
    *AUX_MU_IER = 0;
    *AUX_MU_IIR = 0xC6;    // disable interrupts
    *AUX_MU_BAUD = 270;    // 115200 baud
    /* map UART1 to GPIO pins */
    r=*GPFSEL1;
    r&=~((7<<12)|(7<<15)); // gpio14, gpio15
    r|=(2<<12)|(2<<15);    // alt5
    *GPFSEL1 = r;
    *GPPUD = 0;            // enable pins 14 and 15
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = (1<<14)|(1<<15);
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = 0;        // flush GPIO setup
    *AUX_MU_CNTL = 3;      // enable Tx, Rx
}

/**
 * Send a character
 */
void coot_uart1__putc(char c) {
    /* wait until we can putc */
    do{asm volatile("nop");}while(!(*AUX_MU_LSR&0x20));
    /* write the character to the buffer */
    *AUX_MU_IO=c;
}

/**
 * Receive a character
 */
char coot_uart1__getc(void) {
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
void coot_uart1__puts(char *s) {
    while(*s) {
        /* convert newline to carrige return + newline */
        if(*s=='\n')
            coot_uart1__putc('\r');
        coot_uart1__putc(*s++);
    }
}

/**
 * Display a binary value in hexadecimal
 */
void coot_uart1__putx(uint32_t d) {
    coot_uart1__puts("0x");
    for(int c=28; c>=0; c-=4) {
        byte_t n = (d >> c) & 0x0F;
        n += (n > 9) ? 0x37 : 0x30;
        coot_uart1__putc(n);
    }
}