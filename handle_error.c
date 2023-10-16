#include "main.h"

/**
 * str_error - handles str error
 * @c: char
 *
 * Return: int
 */
int str_error(char c)
{
	if (c == ' ')
	{
		_putchar('%');
		_putchar(c);
		return (2);
	}
	else
	{
		_putchar('%');
		return (1);
	}
	return (0);
}
