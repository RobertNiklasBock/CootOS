#include <types.h>

static unsigned short* VGA_BUFFER = (unsigned short*) 0xb8000;

void print(char* str) 
{
    for(uint32 i = 0; str[i] != '\0'; i++)
    {
        VGA_BUFFER[i] = (VGA_BUFFER[i] & 0xFF00) | str[i];
    }
}

typedef void (*constructor)();
extern "C" constructor* start_ctors;
extern "C" constructor* end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i=start_ctors;i!=end_ctors;i++){
        (*i)();
    }
}


extern "C" 
void kernelMain(void* multiboot_structure, uint32 magicnumber)
{ 
    print("Hello World");
    while(1);
}