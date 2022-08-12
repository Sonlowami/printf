#include "main.h"
#include <stddef.h>
/**
 * main - test the printf function
 *
 * Return: 0 upon success
 */
int main(void)
{
	char c;
	char *p;
	_printf("This is the %s string\n", "first");
	_printf("%c is a char\n", 'v');

	c = '&';
	p = NULL;
	_printf("An ampersand is %c, did you know?\n", c);
	_printf("How do you handle %s nudity\n", p);
	return (0);
}
