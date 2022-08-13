#include "main.h"
/**
 * _printf - print strings, characters and %
 * @format: format string
 *
 * Return: number of bytes printed.
 */
int _printf(const char *format, ...)
{
	int i, count, b_index;
	va_list args;
	/*Create an array to hold format string*/
	char fm_str[BUFF];
	fmt fmt_and_fx[] = {
		{'c', print_ch},
		{'s', print_str},
		{'b', binconv},
		{'%', print_percent}
	};

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	for (i = 0, b_index = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			fm_str[b_index] = format[i];
			printer(fm_str, b_index);
			count++;
			b_index++;
		}
		else
		{
			int j;

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
	write (1, fm_str + index, 1);
}
