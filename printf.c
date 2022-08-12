#include <unistd.h>
#include <stdarg.h>

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
		return (0);
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
			if (format[i + 1] == 'c')
			{
				int x;
			       
				x = va_arg(args, int);
				write(1, &x, 1);
				count++;
			}
			else if (format[i + 1] == 's')
			{
				char *x;

				x = va_arg(args, char *);
				if (x != NULL)
				{
					while (*x != '\0')
					{
						write(1, x, 1);
						count++;
						x++;
					}
				}
			}
			else if(format[i + 1] == '%')
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
