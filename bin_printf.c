#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

void binconv(int x, int *count);
/**
 * _printf - print binary value of a decimal number
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(char *format, ...)
{
	int i, count;
	va_list args;

	if (*format == '\0' || format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0, count = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			if (format[i + 1] == 'b')
			{
				int x;

				x = va_arg(args, int);
				binconv(x, &count);
				i++;
			}
		}
	}
	va_end(args);
	return (count);
}
/**
 * binconv - convert to binary
 * @x: the number to convert
 * @count: pointer to number of bytes computed in the
 *	calling function
 */
void binconv(int x, int *count)
{
	int i;
	int bits[100];

	i = 0;
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
