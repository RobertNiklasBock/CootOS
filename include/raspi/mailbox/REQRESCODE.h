#pragma once
#define NASP(name)  coot_raspi_mailbox__##name
#define CNASP(name) COOT_RASPI_MAILBOX__##name

/**
 * The ReqResCode for a request.
 */
#define COOT_RASPI_MAILBOX__REQRESCODE_REQUEST (0x00000000)

/**
 * The ReqResCode for a successfully answered request.
 */
#define COOT_RASPI_MAILBOX__REQRESCODE_SUCCESS (0x80000000)

/**
 * The ReqResCode for an unsuccessfully answered request.
 */
#define COOT_RASPI_MAILBOX__REQRESCODE_ERROR   (0x80000001)

#undef NASP
#undef CNASP
