#include "main.h"
/**
 * print_oct - prints an octal number.
 * @ap: arguments.
 * @count: character to be printed
 * Return: counter.
 */
int print_oct(va_list ap, int *count)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(ap, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

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
 * Return: counter.
*/
int print_hex(va_list ap, int *count)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(ap, unsigned int);
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
 * Return: counter.
*/
int print_HEX(va_list ap, int *count)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(ap, unsigned int);
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
	*count += counter;
	return (counter);
}
