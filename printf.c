#include "main.h"
/**
 * _printf - print strings, characters and %
 * @format: format string
 *
 * Return: number of bytes printed.
 */
int _printf(const char *format, ...)
{
	int i, count;
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			if (format[i + 1] == 'b')
				binconv(args, &count);
			if (format[i + 1] == 'c')
			{
				print_ch(args, &count);
			}
			else if (format[i + 1] == 's')
			{
				print_str(args, &count);
			}
			else if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				count++;
			}
			i++;
		}
	}
	va_end(args);
	return (count);
}
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
 * printf_str - print a string parameter
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
	int bits[100];

	i = 0;
	x = va_arg(args, int);
	while (x > 0)
	{
		bits[i] = x % 2 + '0';
		i++;
		x /= 2;
	}
	i--;
	for (; i >= 0; i--)
	{
		write(1, &bits[i], 1);
		(*count)++;
	}
}
