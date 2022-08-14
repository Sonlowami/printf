#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFF 1024

/**
 * fmt - typedef of struct format that relates a format
 *	specifier to the function it calls
 */
typedef struct format
{
	char fmt;
	int (*print_function)(va_list pars, int *);
} fmt;

int _printf(const char *format, ...);

int print_str(va_list pars, int *);

int print_ch(va_list args, int *);

int binconv(va_list args, int *count);

int print_percent(va_list, int *);

void printer(char *, int);

int print_dec(va_list args);

int print_int(va_list args, int *);

int _putchar(char cHar);

int print_mem(va_list list, int *count);

int print_rot13(va_list list, int *count);

char *rot13(char *str, char *);
#endif
