#include "raspi/mailbox.h"

volatile uint32_t __attribute__((aligned(16))) coot_mailbox__buffer[36];

/**
 * Sends a TagList to the MailBox and reads back untils it receives an answer.
 */
uint8_t coot_mailbox__call(byte_t ch) {
    uint32_t mailbox_addr = ((((uint32_t) &coot_mailbox__buffer) & ~0xF) | (ch & 0xF));
    wait_until(coot_mailbox__can_send());
    *MBOX_WRITE = mailbox_addr;
    while(1) {
        wait_until(coot_mailbox__can_read());
        /* is it a response to our message? */
        if(mailbox_addr == *MBOX_READ)
            /* is it a valid successful response? */
            return coot_mailbox__buffer[1]==MBOX_RESPONSE;
    }
}

/**
 * Checks if the MailBox can send a TagList.
 */
uint8_t coot_mailbox__can_send() {
    return !(*MBOX_STATUS & MBOX_FULL);
}

uint8_t coot_mailbox__can_read() {
    return !(*MBOX_STATUS & MBOX_EMPTY);
}
