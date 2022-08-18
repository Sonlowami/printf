#include "main.h"
/**
 * print_oct - prints an octal number.
 * @ap: arguments.
 * @count: character to be printed
 * @sz: the size specifier
 * Return: counter.
 */
int print_oct(va_list ap, int *count, int sz)
{
	int i, *array, counter = 0;
	unsigned long int num, temp;

	num = va_arg(ap, long int);
	num = convert_size(num, sz);
	temp = num;
	while (num / 8 != 0)
	{
		num /= 8;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 8;
		temp /= 8;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar(array[i] + '0');
	}
	free(array);
*count += counter;
	return (counter);
}

/**
 * print_hex - prints an hexdecimal number.
 * @ap: arguments.
 * @count: number of bytes printed so far
 * @sz: the size specifier value
 * Return: counter.
*/
int print_hex(va_list ap, int *count, int sz)
{
	int i;
	int *array;
	int counter = 0;
	unsigned long int num = va_arg(ap, unsigned long int);
	unsigned long int temp = num;

	num = convert_size(num, sz);
	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
*count += counter;
	return (counter);
}

/**
 * print_HEX - prints an hexdecimal number.
 * @ap: arguments.
 * @count: number of bytes printed so far
 * @sz: the size specifier value
 * Return: counter.
*/
int print_HEX(va_list ap, int *count, int sz)
{
	int i;
	int *array;
	int counter = 0;
	unsigned long int num = va_arg(ap, unsigned long int);
	unsigned long int temp = num;

	num = convert_size(num, sz);
	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(long int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	*count += counter;
	return (counter);
}
/**
 * print_x - prints an hexadecimal number.
 * @num: number to print.
 * Return: counter.
 */

int print_x(unsigned int num)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
/**
 * print_xcv_string  - handle non-printable characters
 * @ap: list of runtime arguments
 * @count: pointer to number of printed bytes already
 * @sz: the size specifier(nott applicable in this case
 *
 * Return: used space
 */
int print_xcv_string(va_list ap, int *count, int sz)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(ap, char *);
	UN_NEEDED(sz);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_x(cast);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
*count += len;
	return (len);
}
