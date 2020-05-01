#pragma once
#define NASP(name)  coot_raspi_mailbox__##name
#define CNASP(name) COOT_RASPI_MAILBOX__##name

#pragma region Meta
    #define COOT_RASPI_MAILBOX__TAGID_NULL                               (0x00000000)
#pragma endregion // Meta

#pragma region VideoCore
    #define COOT_RASPI_MAILBOX__TAGID_GET_FIRMWARE_VERSION               (0x00000001)
    #define COOT_RASPI_MAILBOX__TAGID_GET_BOARD_MODEL                    (0x00010001)
    #define COOT_RASPI_MAILBOX__TAGID_GET_BOARD_REVISION                 (0x00010002)
    #define COOT_RASPI_MAILBOX__TAGID_GET_BOARD_MAC_ADDRESS              (0x00010003)
    #define COOT_RASPI_MAILBOX__TAGID_GET_BOARD_SERIAL                   (0x00010004)
    #define COOT_RASPI_MAILBOX__TAGID_GET_ARM_MEMORY                     (0x00010005)
    #define COOT_RASPI_MAILBOX__TAGID_GET_VC_MEMORY                      (0x00010006)
    #define COOT_RASPI_MAILBOX__TAGID_GET_CLOCKS                         (0x00010007)
#pragma endregion // VideoCore
   
#pragma region Config
    #define COOT_RASPI_MAILBOX__TAGID_GET_COMMAND_LINE                   (0x00050001)
#pragma endregion // Config
    
#pragma region Shared Resource Management
    #define COOT_RASPI_MAILBOX__TAGID_GET_DMA_CHANNELS                   (0x00060001)
#pragma endregion // Shared Resource Management
    
#pragma region Power
    #define COOT_RASPI_MAILBOX__TAGID_GET_POWER_STATE                    (0x00020001)
    #define COOT_RASPI_MAILBOX__TAGID_GET_TIMING                         (0x00020002)
    #define COOT_RASPI_MAILBOX__TAGID_SET_POWER_STATE                    (0x00028001)
#pragma endregion // Power
    
#pragma region Clock
    #define COOT_RASPI_MAILBOX__TAGID_GET_CLOCK_STATE                    (0x00030001)
    #define COOT_RASPI_MAILBOX__TAGID_SET_CLOCK_STATE                    (0x00038001)
    #define COOT_RASPI_MAILBOX__TAGID_GET_CLOCK_RATE                     (0x00030002)
    #define COOT_RASPI_MAILBOX__TAGID_SET_CLOCK_RATE                     (0x00038002)
    #define COOT_RASPI_MAILBOX__TAGID_GET_MAX_CLOCK_RATE                 (0x00030004)
    #define COOT_RASPI_MAILBOX__TAGID_GET_MIN_CLOCK_RATE                 (0x00030007)
    #define COOT_RASPI_MAILBOX__TAGID_GET_TURBO                          (0x00030009)
    #define COOT_RASPI_MAILBOX__TAGID_SET_TURBO                          (0x00038009)
#pragma endregion // Clock

#pragma region Voltage
    #define COOT_RASPI_MAILBOX__TAGID_GET_VOLTAGE                        (0x00030003)
    #define COOT_RASPI_MAILBOX__TAGID_SET_VOLTAGE                        (0x00038003)
    #define COOT_RASPI_MAILBOX__TAGID_GET_MAX_VOLTAGE                    (0x00030005)
    #define COOT_RASPI_MAILBOX__TAGID_GET_MIN_VOLTAGE                    (0x00030008)
    #define COOT_RASPI_MAILBOX__TAGID_GET_TEMPERATURE                    (0x00030006)
    #define COOT_RASPI_MAILBOX__TAGID_GET_MAX_TEMPERATURE                (0x0003000A)
#pragma endregion // Voltage
    
#pragma region Memory
    #define COOT_RASPI_MAILBOX__TAGID_ALLOCATE_MEMORY                    (0x0003000C)
    #define COOT_RASPI_MAILBOX__TAGID_LOCK_MEMORY                        (0x0003000D)
    #define COOT_RASPI_MAILBOX__TAGID_UNLOCK_MEMORY                      (0x0003000E)
    #define COOT_RASPI_MAILBOX__TAGID_RELEASE_MEMORY                     (0x0003000F)
    #define COOT_RASPI_MAILBOX__TAGID_EXECUTE_CODE                       (0x00030010)
    #define COOT_RASPI_MAILBOX__TAGID_GET_DISPMANX_RESOURCE_MEM_HANDLE   (0x00030014)
    #define COOT_RASPI_MAILBOX__TAGID_GET_EDID_BLOCK                     (0x00030020)

#pragma endregion // Memory

#pragma region FrameBuffer
    #define COOT_RASPI_MAILBOX__TAGID_ALLOCATE_BUFFER                    (0x00040001)
    #define COOT_RASPI_MAILBOX__TAGID_RELEASE_BUFFER                     (0x00048001)
    #define COOT_RASPI_MAILBOX__TAGID_BLANK_SCREEN                       (0x00040002)
    #define COOT_RASPI_MAILBOX__TAGID_GET_PHYSICAL_DISPLAY_WIDTH_HEIGHT  (0x00040003)
    #define COOT_RASPI_MAILBOX__TAGID_TEST_PHYSICAL_DISPLAY_WIDTH_HEIGHT (0x00044003)
    #define COOT_RASPI_MAILBOX__TAGID_SET_PHYSICAL_DISPLAY_WIDTH_HEIGHT  (0x00048003)
    #define COOT_RASPI_MAILBOX__TAGID_GET_VIRTUAL_BUFFER_WIDTH_HEIGHT    (0x00040004)
    #define COOT_RASPI_MAILBOX__TAGID_TEST_VIRTUAL_BUFFER_WIDTH_HEIGHT   (0x00044004)
    #define COOT_RASPI_MAILBOX__TAGID_SET_VIRTUAL_BUFFER_WIDTH_HEIGHT    (0x00048004)
    #define COOT_RASPI_MAILBOX__TAGID_GET_DEPTH                          (0x00040005)
    #define COOT_RASPI_MAILBOX__TAGID_TEST_DEPTH                         (0x00044005)
    #define COOT_RASPI_MAILBOX__TAGID_SET_DEPTH                          (0x00048005)
    #define COOT_RASPI_MAILBOX__TAGID_GET_PIXEL_ORDER                    (0x00040006)
    #define COOT_RASPI_MAILBOX__TAGID_TEST_PIXEL_ORDER                   (0x00044006)
    #define COOT_RASPI_MAILBOX__TAGID_SET_PIXEL_ORDER                    (0x00048006)
    #define COOT_RASPI_MAILBOX__TAGID_GET_ALPHA_MODE                     (0x00040007)
    #define COOT_RASPI_MAILBOX__TAGID_TEST_ALPHA_MODE                    (0x00044007)
    #define COOT_RASPI_MAILBOX__TAGID_SET_ALPHA_MODE                     (0x00048007)
    #define COOT_RASPI_MAILBOX__TAGID_GET_PITCH                          (0x00040008)
    #define COOT_RASPI_MAILBOX__TAGID_GET_VIRTUAL_BUFFER_OFFSET          (0x00040009)
    #define COOT_RASPI_MAILBOX__TAGID_TEST_VIRTUAL_BUFFER_OFFSET         (0x00044009)
    #define COOT_RASPI_MAILBOX__TAGID_SET_VIRTUAL_BUFFER_OFFSET          (0x00048009)
    #define COOT_RASPI_MAILBOX__TAGID_GET_OVERSCAN                       (0x0004000A)
    #define COOT_RASPI_MAILBOX__TAGID_TEST_OVERSCAN                      (0x0004400A)
    #define COOT_RASPI_MAILBOX__TAGID_SET_OVERSCAN                       (0x0004800A)
    #define COOT_RASPI_MAILBOX__TAGID_GET_PALETTE                        (0x0004000B)
    #define COOT_RASPI_MAILBOX__TAGID_TEST_PALETTE                       (0x0004400B)
    #define COOT_RASPI_MAILBOX__TAGID_SET_PALETTE                        (0x0004800B)
    #define COOT_RASPI_MAILBOX__TAGID_SET_CURSOR_INFO                    (0x00008010)
    #define COOT_RASPI_MAILBOX__TAGID_SET_CURSOR_STATE                   (0x00008011)
#pragma endregion // FrameBuffer

#undef NASP
#undef CNASP


