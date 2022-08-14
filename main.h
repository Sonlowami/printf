#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
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

int _putchar(char cHar);


#endif
