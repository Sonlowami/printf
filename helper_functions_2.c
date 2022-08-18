#include "main.h"

/**
 * _putchar - writes the charac to stdout
 * @cHar: The character to be printed.
 *
 * Return: Always 1 on success
 * on error, -1 is returned
 */

int _putchar(char cHar)
{
	return (write(1, &cHar, 1));
}

/**
 * print_int - prints integer
 * @args: argument to print
 * @count: number of bytes printed so far
 * @sz: the size parameter for int
 * Return: number of characters printed
 */
int print_int(va_list args, int *count, int sz)
{
	int last, digit, i = 1;
	long int n, num, exp = 1;

	n = va_arg(args, long int);
	n = convert_size(n, sz);
	last = n % 10;
	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
_putchar(last + '0');
*count += i;
return (i);
}

/**
 * print_dec - prints decimal
 * @args: argument to print
 * @count: number of bytes printed so far
 * @sz: the size specifier
 * Return: number of characters printed
*/
int print_dec(va_list args, int *count, int sz)
{
	int last, digit;
	long int n, exp = 1, num;
	int  i = 1;

	n = va_arg(args, long int);
	n = convert_size(n, sz);
	last = n % 10;
	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
_putchar(last + '0');
*count += i;
return (i);
}
/**
 * print_unsigned - print an unsugned int from
 * runtime arguments
 * @args: list of runtime arguments
 * @count: number of bytes printed so far
 * @sz: the size specifier
 *
 * Return: i
 */
int print_unsigned(va_list args, int *count, int sz)
{
	unsigned long int n, num, exp = 1;
	int last, digit;
	int  i = 1;

	n = va_arg(args, unsigned long int);
	n = convert_size(n, sz);
	last = n % 10;
	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');
*count += i;
	return (i);
}
/**
 * convert_size - convert size of a numeric variable
 * @n: the integer variable
 * @sz: the new size marker
 *
 * Return: the changed variable size
 */
long int convert_size(long int n, int sz)
{
	if (sz == 2)
		return ((short)n);
	if (sz == 1)
		return (n);
	else
		return ((int)n);
}
