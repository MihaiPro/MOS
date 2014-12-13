#include <tty.h>
#include <vga.h>
#include <string.h>
#include <bit.h>

size_t tty_row;
size_t tty_column;
uint8_t tty_color;
uint16_t* tty_buffer;
 
void tty_initialize(vga_color fg, vga_color bg)
{
	tty_row = 0;
	tty_column = 0;
	tty_color = make_color(fg, bg);
	tty_buffer = (uint16_t*) 0xB8000;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for ( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			tty_buffer[index] = make_vgaentry(' ', tty_color);
		}
	}
}
 
void tty_setcolor(uint8_t color)
{
	tty_color = color;
}
 
void tty_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	tty_buffer[index] = make_vgaentry(c, color);
}
 
void tty_putchar(char c)
{
	if (c == '\n') {
		++tty_row;
		tty_column = -1;
	} else if (c == '\t') {
		tty_column += 4;
	} else if (c == '\b') {
		tty_column -= 1;
		if (tty_column < 0) {
			tty_column = -1;
			tty_row -= 1;
		}
	} else { 
		tty_putentryat(c, tty_color, tty_column, tty_row);
	}

	if ( ++tty_column == VGA_WIDTH )
	{
		tty_column = 0;
		if ( ++tty_row == VGA_HEIGHT )
		{
			tty_row = 0;
		}
	}
	move_cursor();
}
 
void tty_writestring(const char* data)
{
	size_t datalen = strlen(data);
	for ( size_t i = 0; i < datalen; i++ )
		tty_putchar(data[i]);
}

void tty_write_colored(const char* data, vga_color fg, vga_color bg)
{
	uint8_t default_color = tty_color;
	tty_setcolor(make_color(fg, bg));
	tty_writestring(data);
	tty_setcolor(default_color);
}

void move_cursor()
{
   uint16_t cursorLocation = tty_row * 80 + tty_column;
   outb(0x3D4, 14);
   outb(0x3D5, cursorLocation >> 8);
   outb(0x3D4, 15);     
   outb(0x3D5, cursorLocation);   
}
