#pragma once
#define NASP(name) coot_raspi__##name

#include "std/inttypes.h"

typedef struct NASP(MailBoxMessage) {
    uint32_t address: 28;
    uint8_t channel: 4;
} NASP(MailBoxMessage_t);

typedef struct NASP(MailBoxMessageBuffer) {
    uint32_t size;
    uint32_t type;
    uint8_t tags[1];
} NASP(MailBoxMessageBuffer_t);

typedef enum NASP(MailBoxChannelID) { 
    POWER       = 0,
    FRAMEBUFFER = 1,
    VUART       = 2,
    VCHIQ       = 3,
    LEDS        = 4,
    BUTTONS     = 5,
    TOUCH       = 6,
    COUNT       = 7,
    PROPERTY    = 8
} NASP(MailBoxChannelID_t);

typedef enum NASP(MailBoxMessageTagID) {
    #pragma region Meta
        NULL                               = 0x00000000,
    #pragma endregion // Meta

    #pragma region VideoCore
        GET_FIRMWARE_VERSION               = 0x00000001,
        GET_BOARD_MODEL                    = 0x00010001,
        GET_BOARD_REVISION                 = 0x00010002,
        GET_BOARD_MAC_ADDRESS              = 0x00010003,
        GET_BOARD_SERIAL                   = 0x00010004,
        GET_ARM_MEMORY                     = 0x00010005,
        GET_VC_MEMORY                      = 0x00010006,
        GET_CLOCKS                         = 0x00010007,
    #pragma endregion // VideoCore
   
    #pragma region Config
        GET_COMMAND_LINE                   = 0x00050001,
    #pragma endregion // Config
    
    #pragma region Shared Resource Management
        GET_DMA_CHANNELS                   = 0x00060001,
    #pragma endregion // Shared Resource Management
    
    #pragma region Power
        GET_POWER_STATE                    = 0x00020001,
        GET_TIMING                         = 0x00020002,
        SET_POWER_STATE                    = 0x00028001,
    #pragma endregion // Power
    
    #pragma region Clock
        GET_CLOCK_STATE                    = 0x00030001,
        SET_CLOCK_STATE                    = 0x00038001,
        GET_CLOCK_RATE                     = 0x00030002,
        SET_CLOCK_RATE                     = 0x00038002,
        GET_MAX_CLOCK_RATE                 = 0x00030004,
        GET_MIN_CLOCK_RATE                 = 0x00030007,
        GET_TURBO                          = 0x00030009,
        SET_TURBO                          = 0x00038009,
    #pragma endregion // Clock

    #pragma region Voltage
        GET_VOLTAGE                        = 0x00030003,
        SET_VOLTAGE                        = 0x00038003,
        GET_MAX_VOLTAGE                    = 0x00030005,
        GET_MIN_VOLTAGE                    = 0x00030008,
        GET_TEMPERATURE                    = 0x00030006,
        GET_MAX_TEMPERATURE                = 0x0003000A,
    #pragma endregion // Voltage
    
    #pragma region Memory
        ALLOCATE_MEMORY                    = 0x0003000C,
        LOCK_MEMORY                        = 0x0003000D,
        UNLOCK_MEMORY                      = 0x0003000E,
        RELEASE_MEMORY                     = 0x0003000F,
        EXECUTE_CODE                       = 0x00030010,
        GET_DISPMANX_RESOURCE_MEM_HANDLE   = 0x00030014,
        GET_EDID_BLOCK                     = 0x00030020,

    #pragma endregion // Memory

    #pragma region FrameBuffer
        ALLOCATE_BUFFER                    = 0x00040001,
        RELEASE_BUFFER                     = 0x00048001,
        BLANK_SCREEN                       = 0x00040002,
        GET_PHYSICAL_DISPLAY_WIDTH_HEIGHT  = 0x00040003,
        TEST_PHYSICAL_DISPLAY_WIDTH_HEIGHT = 0x00044003,
        SET_PHYSICAL_DISPLAY_WIDTH_HEIGHT  = 0x00048003,
        GET_VIRTUAL_BUFFER_WIDTH_HEIGHT    = 0x00040004,
        TEST_VIRTUAL_BUFFER_WIDTH_HEIGHT   = 0x00044004,
        SET_VIRTUAL_BUFFER_WIDTH_HEIGHT    = 0x00048004,
        GET_DEPTH                          = 0x00040005,
        TEST_DEPTH                         = 0x00044005,
        SET_DEPTH                          = 0x00048005,
        GET_PIXEL_ORDER                    = 0x00040006,
        TEST_PIXEL_ORDER                   = 0x00044006,
        SET_PIXEL_ORDER                    = 0x00048006,
        GET_ALPHA_MODE                     = 0x00040007,
        TEST_ALPHA_MODE                    = 0x00044007,
        SET_ALPHA_MODE                     = 0x00048007,
        GET_PITCH                          = 0x00040008,
        GET_VIRTUAL_BUFFER_OFFSET          = 0x00040009,
        TEST_VIRTUAL_BUFFER_OFFSET         = 0x00044009,
        SET_VIRTUAL_BUFFER_OFFSET          = 0x00048009,
        GET_OVERSCAN                       = 0x0004000A,
        TEST_OVERSCAN                      = 0x0004400A,
        SET_OVERSCAN                       = 0x0004800A,
        GET_PALETTE                        = 0x0004000B,
        TEST_PALETTE                       = 0x0004400B,
        SET_PALETTE                        = 0x0004800B,
        SET_CURSOR_INFO                    = 0x00008010,
        SET_CURSOR_STATE                   = 0x00008011
    #pragma endregion // FrameBuffer

} NASP(MailBoxMessageTagID_t);

void coot_mailbox__init();
void coot_mailbox__sendTags();

#undef NASP
