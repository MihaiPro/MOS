.PHONY: all clean prep

INCLUDES = -Iinclude

API_OBJS = 
MATH_OBJS = 
STDIO_OBJS = 
STDLIB_OBJS = stdlib/itoa.o \
				stdlib/htoa.o 
STRING_OBJS = string/strlen.o \
				string/strcpy.o \

ALL_OBJS = $(API_OBJS) \
			$(MATH_OBJS) \
			$(STDIO_OBJS) \
			$(STDLIB_OBJS) \
			$(STRING_OBJS) \

all: prep libc.a

libc.a: $(ALL_OBJS)
	$(AR) rcs libc.a $(ALL_OBJS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

clean:
	rm $(ALL_OBJS)
	rm libc.a
