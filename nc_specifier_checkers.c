#include "main.h"
/**
 * check_size - check the size specifier
 * @c: the specifier
 * 
 * Return: 1 if l, 2 if h, 0 ootherwise
 */
int check_size(char c)
{
	if (c == 'l')
		return (1);
	else if(c == 'h')
		return (2);
	return (0);
}
