.PHONY: all clean

INCLUDES = -Iinclude/ -I../libc/include
LIBS = -L. -lkern -L../libc -lc

LIBKERN_OBJS = arch/tty.o \
				arch/vga.o \
				arch/bit.o \

all: libkern.a kernel.o

libkern.a: $(LIBKERN_OBJS)
	$(AR) rcs libkern.a $(LIBKERN_OBJS)

kernel.o: kernel.c
	$(CC) kernel.c -c -o kernel.o $(CFLAGS) $(INCLUDES) $(LIBS) 

%.o: %.c
	 $(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES) $(LIBS)

clean:
	rm $(LIBKERN_OBJS)
	rm kernel.o
	rm libkern.a
