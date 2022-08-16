#include "main.h"
/**
 * _printf - print strings, characters and %
 * @format: format string
 *
 * Return: number of bytes printed.
 */
int _printf(const char *format, ...)
{
	int i, count, b_index, size;
	va_list args;
	/*Create an array to hold format string*/
	char fm_str[BUFF];

	if (!format || (format[0] == '%' && format[1] == ' ' && format[2] == '\0'))
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
			if ((size = check_size(format[i + 1])) != 0)
				i++;
			print_caller(args, &count, format[i + 1], size);
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
/**
 * print_caller - call the specifier handler
 * @list: list ofruntime arguments
 * @count: pointer to number of bytes printed so far
 * @sp: the format specifier
 * @sz: the state of the size specifier
 */
void print_caller(va_list list, int *count, char sp, int sz)
{
	fmt fmt_and_fx[] = {
		{'c', print_ch}, {'s', print_str},
		{'b', binconv}, {'%', print_percent},
		{'i', print_int}, {'p', print_mem}, {'R', print_rot13},
		{'c', print_ch}, {'S', print_str},
		{'b', binconv},	{'%', print_percent},
		{'i', print_int}, {'d', print_dec},
		{'u', print_unsigned}, {'o', print_oct},
		{'x', print_hex}, {'X', print_HEX}, {'r', reverse}
	};
	int i;

	for (i = 0; fmt_and_fx + i; i++)
	{
		if (sp == fmt_and_fx[i].fmt)
		{
			fmt_and_fx[i].print_function(list, count, sz);
			break;
		}
	}
}
