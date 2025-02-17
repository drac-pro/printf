#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#define PLUS_FLAG  (1 << 0)
#define SPACE_FLAG (1 << 1)
#define HASH_FLAG  (1 << 2)
#define ZERO_FLAG  (1 << 3)
#define MINUS_FLAG (1 << 4)


#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier_format - struct type_f
 * @spec: character representing the type of the specifier
 * @f: pointer to a function to handle that specifier
 */
typedef struct specifier_format
{
	char spec;
	int (*f)(va_list args, int flags);
} spec_f;

int _putchar(char c);
void flush_buffer(void);
int _printf(const char *format, ...);

int p_chr(va_list args, int flags);
int p_str(va_list args, int flags);
int p_percent(va_list args, int flags);
int p_di(va_list args, int flags);
int p_b(va_list args, int flags);
int print_u(va_list args, int flags);
int print_o(va_list args, int flags);
int print_x(va_list args, int flags);
int print_X(va_list args, int flags);
int print_S(va_list args, int flags);
int print_p(va_list args, int flags);

int p_diou_helper(unsigned int n, int base);
int print_binary(unsigned int n);
int p_xX_helper(unsigned int n, char x);
int print_address(void *str);

int passer(const char *format, spec_f specs[], va_list args);
int parse_flags(const char *format, int *i);

int str_error(char c);

#endif /*MAIN_H*/
