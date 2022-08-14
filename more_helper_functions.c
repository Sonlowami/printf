#include "main.h"

/**
 * print_rot13 - print rot 13 of a string
 * @list: the array of runtime arguments
 * @count: number of printed bytes so far
 *
 * Return: 0
 */
int print_rot13(va_list list, int *count)
{
	char *rot, *norm;

	norm = va_arg(list, char *);
	if (norm != NULL)
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
	}
	return (p);
}
