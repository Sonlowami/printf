#include "main.h"

/**
 * print_ch - print single char at a time
 * @args: list of runtime arguments
 * @count: pointer to count of printed bytes
 */
void print_ch(va_list args, int *count)
{
	int x;

	x = va_arg(args, int);
	write(1, &x, 1);
	(*count)++;
}
/**
 * print_str - print a string parameter
 * @pars: the list of variable type arguments
 * @count: pointer to number of chars printed so far
 */
void print_str(va_list pars, int *count)
{
	char *x;

	x = va_arg(pars, char *);
	if (x != NULL)
	{
		while (*x != '\0')
		{
			write(1, x, 1);
			(*count)++;
			x++;
		}
	}
}

/**
 * binconv - convert to binary
 * @args: list of runtime arguments
 * @count: pointer to number of bytes computed in the
 *	calling function
 */
void binconv(va_list args, int *count)
{
	int i, x;
	char bits[100];

	i = 0;
	x = va_arg(args, int);
	while (x > 0)
	{
		bits[i++] = x % 2 + '0';
		x /= 2;
	}
	for (i -= 1; i >= 0; i--)
	{
		printer(bits, i);
		(*count)++;
	}
}
/**
 * print_percent - print a percent sign
 * @list - a list of runtime arguments
 * @count: pointer to number of chars printed
 */
void print_percent(va_list list, int *count)
{
	char x;
	
	(void)list;
	x = '%';
	write (1, &x, 1);
	(*count)++;
}
