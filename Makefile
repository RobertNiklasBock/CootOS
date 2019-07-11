SRCS = $(shell find . -name '*.cpp')
OBJS = $(SRCS:.cpp=.o)

GPPPARAMS   = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
GPPINCLUDES = -I header/
LDPARAMS    = -melf_i386

objects = $(OBJS) boot_sector.o

%.o: %.cpp
	g++ $(GPPPARAMS) $(GPPINCLUDES) -o $@ -c $<

%.o: %.asm
	nasm -f bin $< -o $@ 
	
mykernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

install: mykernel.bin
	sudo cp $< /boot/mykernel.bin
	
mykernel.iso: mykernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout-0' >> iso/boot/grub/grub.cfg
	echo 'set default-0' >> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System"{' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/mykernel.bin' >> iso/boot/grub/grub.cfg
	echo ' boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso 

clean:
	rm $(objects)
	
# run: mykernel.iso
# 	(killall VirtualBox && sleep 1) || true
# 	VirtualBox --startvm "My Operating System" &
