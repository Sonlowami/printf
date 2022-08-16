#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF 1024
#define UN_NEEDED(X) (void)X

/**
 * struct format - print functions
 * @pars: va_list of parameters
 * @fmt: typedef of struct format that relates a format
 *	specifier to the function it calls
 */
typedef struct format
{
	char fmt;
	int (*print_function)(va_list pars, int *, int);
} fmt;

int _printf(const char *format, ...);

int print_str(va_list pars, int *, int);

int print_ch(va_list args, int *, int);

int binconv(va_list args, int *count, int);

int print_percent(va_list, int *, int);

void printer(char *, int);

int print_int(va_list args, int *, int);

int print_dec(va_list args, int *count, int);

int print_unsigned(va_list args, int *count, int);

int print_oct(va_list ap, int *count, int);

int print_hex(va_list ap, int *count, int);

int print_HEX(va_list ap, int *count, int);

int _putchar(char cHar);

int print_mem(va_list list, int *count, int);

int print_rot13(va_list list, int *count, int);

char *rot13(char *str, char *);

int reverse(va_list list, int *count, int);

void print_rev(char *s, int *x);

void print_caller(va_list list, int *count, char sp, int);

int check_size(char c);

int convert_size(int n, int sz);
#endif
