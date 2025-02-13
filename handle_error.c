#include "main.h"

/**
 * str_error - handles str error
 * @c: char
 *
 * Return: int
 */
int str_error(char c)
{
	/* handles unknown format specifier */
	_putchar('%');
	_putchar(c);
	return (2);
}
