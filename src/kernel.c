#include "io/uart1.h"
#include "std/inttypes.h"
#include "time/sleep.h"
#include "raspi/mailbox.h"

#include "raspi/atags/atags.h"

void main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    char buf[256];
    // Declare as unused
    // (void) r0;
    // (void) r1;
    // (void) atags;

    // set up serial console
    coot_uart1__init();
    
    // get the board's unique serial number with a mailbox call
    coot_mailbox__buffer[0] = 7*4;                  // length of the message
    coot_mailbox__buffer[1] = MBOX_REQUEST;         // this is a request message
    
    coot_mailbox__buffer[2] = 0x00000001;   // get serial number command
    coot_mailbox__buffer[3] = 4;                    // buffer size
    coot_mailbox__buffer[4] = 0x00000000;
    coot_mailbox__buffer[5] = 0;                    // clear output buffer
    coot_mailbox__buffer[6] = MBOX_TAG_LAST;

    // coot_mailbox__buffer[7] = MBOX_TAG_LAST;

    // send the message to the GPU and receive answer
    if (coot_mailbox__call(MBOX_CH_PROP)) {
        coot_uart1__puts("My serial number is: ");
        coot_uart1__putx(coot_mailbox__buffer[6]);
        coot_uart1__putx(coot_mailbox__buffer[5]);
        coot_uart1__puts("\n");
    } else {
        coot_uart1__puts("Unable to query serial!\n");
    }
    coot_uart1__puts("Query Memsize\n");
    uint32_t memsize  = coot_raspi_atags__get_mem_size((coot_raspi_atags__Atag_t*) atags);
    coot_uart1__putx(memsize);
    coot_uart1__puts("\n");
    // echo everything back
    while(1) {
        coot_uart1__putc(coot_uart1__getc());
    }   
}
