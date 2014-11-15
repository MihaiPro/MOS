.PHONY: all clean install install-kern install-lib install-boot

INCLUDES = -Ikernel/include
LIBS = 

LDFLAGS = -T kernel/arch/linker.ld -ffreestanding -O2 -nostdlib -lgcc
ASMFLAGS = 
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra

# Objects
KERN_ARCH_OBJS = $(K_ARCH_DIR)/tty.o \
				$(K_ARCH_DIR)/vga.c \

KERN_OBJS = $(KERN_DIR)/kernel.o \

COBJS = $(KERN_ARCH_OBJS) \
		$(KERN_OBJS) \

ASMOBJS = boot/boot.S \

ALL_OBJS = $(COBJS) \
		$(ASMOBJS)

all: mos.bin

mos.bin: $(COBJS) $(ASMOBJS)
	$(CC) $(LDFLAGS) -o mos.bin $(INCLUDES) $(ALL_OBJS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

%.o: %.S
	$(AS) -c $< -o $@

install: install-kern install-lib install-boot

install-kern:
	mkdir sysroot
	mkdir sysroot/usr
	cp -r kernel/include/ sysroot/usr/
	mkdir sysroot/usr/lib
	mkdir sysroot/home
	mkdir sysroot/boot
	cp mos.bin sysroot/boot

# install-lib must be implemented

install-boot:
	mkdir sysroot/boot/grub
	cp boot/grub.cfg sysroot/boot/grub 

clean: 
	rm sysroot -r
	rm mos.iso
	rm mos.bin
