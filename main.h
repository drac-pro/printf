#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#define PLUS_FLAG  (1 << 0)
#define SPACE_FLAG (1 << 1)
#define HASH_FLAG  (1 << 2)
#define ZERO_FLAG  (1 << 3)
#define MINUS_FLAG (1 << 4)

#define LENGTH_NONE 0
#define LENGTH_SHORT 1
#define LENGTH_LONG 2


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
	int (*f)(va_list args, int flags, int length);
} spec_f;

int _putchar(char c);
void flush_buffer(void);
int _printf(const char *format, ...);

int p_chr(va_list args, int flags, int length);
int p_str(va_list args, int flags, int length);
int p_percent(va_list args, int flags, int length);
int p_di(va_list args, int flags, int length);
int p_b(va_list args, int flags, int length);
int print_u(va_list args, int flags, int length);
int print_o(va_list args, int flags, int length);
int print_x(va_list args, int flags, int length);
int print_X(va_list args, int flags, int length);
int print_S(va_list args, int flags, int length);
int print_p(va_list args, int flags, int length);

int p_diou_helper(unsigned long n, int base);
int print_binary(unsigned int n);
int p_xX_helper(unsigned long n, char x);
int print_address(void *str);

unsigned long length_modifier(va_list args, int length);

int passer(const char *format, spec_f specs[], va_list args);
int parse_flags(const char *format, int *i);
int parse_length(const char *format, int *i);

int str_error(char c);

#endif /*MAIN_H*/
