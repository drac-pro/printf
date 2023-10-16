#include "main.h"

/**
 * p_chr -  function prints character
 * @args: arguments to print
 *
 * Return: number of bytes printed
 */
int p_chr(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * p_str -  function print strinf
 * @args: arguments to print
 *
 * Return: number of bytes printed
 */
int p_str(va_list args)
{
	int i;
	const char *str;

	str = va_arg(args, const char *);
	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * p_percent -  function prints character
 *
 * Return: number of bytes printed
 */
int p_percent(void)
{
	_putchar('%');
	return (1);
}
