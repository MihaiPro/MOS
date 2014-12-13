#ifndef TTY_H
#define TTY_H

#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <vga.h>

size_t tty_row;
size_t tty_column;
uint8_t tty_color;
uint16_t* tty_buffer;
 
void tty_initialize(); 
void tty_setcolor(uint8_t color);
void tty_putentryat(char c, uint8_t color, size_t x, size_t y);
void tty_putchar(char c);
void tty_writestring(const char* data);
void tty_write_colored(const char* data, vga_color fg, vga_color bg);
void move_cursor();

#endif
