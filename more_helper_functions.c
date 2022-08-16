#include "main.h"

/**
 * print_rot13 - print rot 13 of a string
 * @list: the array of runtime arguments
 * @count: number of printed bytes so far
 * @sz: size specifier
 *
 * Return: 0
 */
int print_rot13(va_list list, int *count, int sz)
{
	char *rot, *norm;
	
	UN_NEEDED(sz);
	norm = va_arg(list, char *);
	if (norm == NULL)
	{
		rot = "(null)";
		write(1, rot, 6);
		*count += 6;
	}
	else
	{
		int i;

		rot = malloc(strlen(norm));
		rot13(norm, rot);
		for (i = 0; rot[i] != '\0'; i++)
		{
			_putchar(rot[i]);
			(*count)++;
		}
		free(rot);
	}
	return (0);
}
/**
 * rot13 - encodes a string into rot13
 * @str: character array
 * @p: pointer to the return string
 *
 * Return: the pointer str
 */
char *rot13(char *str, char *p)
{
	int i, j;

	char s[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	char rot[52] = {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
		'Z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == s[j])
			{
				p[i] = rot[j];
				break;
			}
		}
		if (str[i] != s[j])
			p[i] = str[i];
	}
	return (p);
}
/**
 * reverse - check a string and call the print function
 * @list: list of runtime arguments
 * @count: the pointer to number of bytes printed so far
 * @sz: the size specifier(unneeded here)
 */
int reverse(va_list list, int *count, int sz)
{
	char *p;

	p = va_arg(list, char *);
	UN_NEEDED(sz);
	if (!p)
	{
		char *nil = "(null)";
		write(1, nil, 6);
		*count += 6;
	}
	else
	{
		print_rev(p, count);
	}
	return (0);
}

/**
 * print_rev - prints a string in the reverse order
 * @s: the string from the calling function
 * @x: number of bytes written on screen so far
 */
void print_rev(char *s, int *x)
{
	int i, j;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);
	_putchar('\n');
	*x += i;
}
