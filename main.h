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
	void (*print_function)(va_list pars, int *);
}fmt;

int _printf(const char *format, ...);

void print_str(va_list pars, int *);

void print_ch(va_list args, int *);

void binconv(va_list args, int *count);

void print_percent(va_list, int *);

void printer(char *, int);

int print_dec(va_list args);

int print_int(va_list args);

int _putchar(char cHar);


#endif
