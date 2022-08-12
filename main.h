#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
int _printf(const char *format, ...);

void print_str(va_list pars, int *);

void print_ch(va_list args, int *);

void binconv(va_list args, int *count);
#endif
