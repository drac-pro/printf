#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct specifier_format - struct type_f
 * @spec: character representing the type of the specifier
 * @f: pointer to a function to handle that specifier
 */
typedef struct specifier_format
{
	char spec;
	int (*f)(va_list args);
} spec_f;

int _putchar(char c);
int _printf(const char *format, ...);

int p_chr(va_list args);
int p_str(va_list args);
int p_percent(va_list args);
int p_di(va_list args);
int print_binary(unsigned int n);
int p_b(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_hexa(va_list args);
int print_HEXA(va_list args);

int passer(const char *format, spec_f specs[], va_list args);

int str_error(char c);

#endif /*MAIN_H*/
