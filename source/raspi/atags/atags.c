#include "raspi/atags/atags.h"

#include "io/uart0.h"

uint32_t coot_raspi_atags__get_mem_size(coot_raspi_atags__Atag_t* atags) {
#ifdef QEMU
    return 1024*1024*128;
#else
    while(atags->id != COOT_RASPI_ATAGS__TAGID_NONE) {
        if (atags->id == COOT_RASPI_ATAGS__TAGID_MEM) {
            return atags->mem.size;
        }
        atags = (coot_raspi_atags__Atag_t*)(((uint32_t *)atags) + atags->tag_size);
    }
    return 0;
#endif // QEMU
}
