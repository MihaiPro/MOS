.PHONY: all clean install install-kern install-lib install-boot

INCLUDES = -Ikernel/include
LIBS = -Lkernel/ -lkern -Llibc/ -lc

LDFLAGS = -T kernel/arch/linker.ld -ffreestanding -O2 -nostdlib -lgcc
ASMFLAGS = 


# Objects
KERN_OBJS = $(KERN_DIR)/kernel.o \

ASMOBJS = boot/boot.S \

ALL_OBJS = $(KERN_OBJS) \
		$(ASMOBJS)

# Compile and link boot image
all: mos.bin

mos.bin: $(COBJS) $(ASMOBJS)
	$(CC) $(LDFLAGS) $(INCLUDES) $(ALL_OBJS) $(LIBS) -o mos.bin

# Compile all objects
%.o: %.S
	$(AS) -c $< -o $@

# Copy all compiled files to 'sysroot' directory(target dir of iso file) 
install: install-kern install-lib install-boot

install-kern:
	mkdir sysroot
	mkdir sysroot/usr
	mkdir sysroot/usr/include
	cp kernel/include/*.* sysroot/usr/include
	cp libc/include/*.* sysroot/usr/include
	mkdir sysroot/usr/lib
	cp kernel/libkern.a sysroot/usr/lib
	cp libc/libc.a sysroot/usr/lib
	mkdir sysroot/home
	mkdir sysroot/boot
	cp mos.bin sysroot/boot

# install-lib must be implemented

install-boot:
	mkdir sysroot/boot/grub
	cp boot/grub.cfg sysroot/boot/grub 

# Clean work space!
clean: 
	rm sysroot -r
	rm mos.iso
	rm mos.bin
