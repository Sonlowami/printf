#include "main.h"
/**
 * _printf - print strings, characters and %
 * @format: format string
 *
 * Return: number of bytes printed.
 */
int _printf(const char *format, ...)
{
	int i, count, b_index, j;
	va_list args;
	/*Create an array to hold format string*/
	char fm_str[BUFF];
	fmt fmt_and_fx[] = {
		{'c', print_ch}, {'s', print_str},
		{'b', binconv}, {'%', print_percent},
		{'i', print_int}, {'p', print_mem}, {'r', print_rot13},
		{'c', print_ch}, {'S', print_str},
		{'b', binconv},	{'%', print_percent},
		{'i', print_int}, {'d', print_dec},
		{'u', print_unsigned}, {'o', print_oct},
		{'x', print_hex}, {'X', print_HEX}
	};
	if (!format)
		return (-1);
	va_start(args, format);
	for (i = 0, b_index = 0, count = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			fm_str[b_index++] = format[i];
			printer(fm_str, b_index - 1);
			count++;
		}
		else
		{
			for (j = 0; fmt_and_fx + j; j++)
			{
				if (format[i + 1] == fmt_and_fx[j].fmt)
				{
					fmt_and_fx[j].print_function(args, &count);
					break;
				}
			}
			i++;
		}
	}
va_end(args);
return (count);
}

/**
 * printer - write on the standard output
 * @fm_str: an array of chars in the format string
 * @index: index of char to be printed
 */
void printer(char *fm_str, int index)
{
	write(1, fm_str + index, 1);
}
