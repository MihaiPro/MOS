#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include <tty.h>
#include <vga.h>
#include <string.h>
#include <stdlib.h>
 
/* Check if the compiler thinks if we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main()
{
	tty_initialize(COLOR_WHITE, COLOR_MAGENTA);
	/* Since there is no support for newlines in tty_putchar yet, \n will
	   produce some VGA specific character instead. This is normal. */
	char from[] = "Hello!";
	char to[15];

	tty_writestring("Hello, Kernel World!\n");
	tty_writestring("This is my first kernel.\n");
	strcpy(to, from);
	tty_writestring(to);
	tty_writestring("\n");
	tty_writestring(itoa(1234));
	tty_write_colored("\nThis is a test of \'tty_write_colored\'!\n", COLOR_BLUE, COLOR_RED);
	tty_writestring(htoa(0xABC));
}
