# === Settings ================================================================
IMAGE      = kernel8.img
MACHINE    = raspi3
TARGET     = aarch64-elf
LDTARGET   = aarch64elf

USE_QEMU  ?= 1

# === Source Code & Object Files ==============================================
INC_DIR    = inc/
SRC_DIR    = src/
OBJ_DIR    = build/

ENTRYPOINT = start.S
LINKERFILE = link.ld

INC        = $(INC_DIR:%=-I%)
SRC        = $(shell find $(SRCDIR) -name "*.c")
OBJ        = $(SRC:.c=.o)

EP_OBJFILE = $(ENTRYPOINT:.S=.o)
ELFFILE    = $(IMAGE:.img=.elf)


# === Compiler & Tools ========================================================
CC         = clang
CCFLAGS    = --target=$(TARGET) -Wall -O2 -ffreestanding -nostdinc \
             -nostdlib -mcpu=cortex-a53+nosimd

IGNORED_WARNS = -Wno-unknown-pragmas
CCFLAGS   += $(IGNORED_WARNS)


ifeq ($(USE_QEMU), 1)
    CCFLAGS +=-D QEMU
endif

LD         = ld.lld
LDFLAGS    = -m $(LDTARGET)

OBJCOPY    = llvm-objcopy
OBJCPFLAGS = -O binary

QEMU       = qemu-system-aarch64

# === Rules ===================================================================

all: clean $(IMAGE)

tell:
	@echo $(SRC)
	@echo $(OBJ)

run: all
	$(QEMU) -M $(MACHINE) -kernel $(IMAGE) -serial null -serial stdio

clean:
	rm $(IMAGE) $(OBJ) $(EP_OBJFILE) $(ELFFILE) >/dev/null 2>/dev/null || true

$(EP_OBJFILE): $(ENTRYPOINT)
	$(CC) $(CCFLAGS) $(INC) -c $^ -o $@

$(IMAGE): $(EP_OBJFILE) $(OBJ)
	$(LD) $(LDFLAGS) $(EP_OBJFILE) $(OBJ) -T $(LINKERFILE) -o $(ELFFILE)
	$(OBJCOPY) $(OBJCPFLAGS) $(ELFFILE) $(IMAGE)

%.o: %.c
	$(CC) $(CCFLAGS) $(INC) -c $^ -o $@
