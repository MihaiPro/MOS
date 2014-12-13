#include <string.h>

void strcpy(char to[], char from[])
{
	int i = 0;
	for (i = 0; (to[i] = from[i]) != '\0'; ++i) {}
	to[++i] = '\0';
}
