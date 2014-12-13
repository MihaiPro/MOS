#include <stdlib.h>

#define INT_DIGITS 19

char *htoa(i)
     int i;
{
  /* Room for INT_DIGITS digits, 0x and '\0' */
  static char buf[INT_DIGITS + 3];
  char *p = buf + INT_DIGITS + 2;	/* points to terminating '\0' */
  if (i >= 0) {
    do {
      if ('0' + i % 16 <= '9') {
        *--p = '0' + (i % 16);
        i /= 16;
      } else {
        *--p = '7' + (i % 16);
        i /= 16;
      }
    } while (i != 0);
	*--p = 'x';
	*--p = '0';
    return p;
  }
  return p;
}
