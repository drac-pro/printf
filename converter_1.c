#include "main.h"

/**
 * p_chr -  function prints character
 * @args: arguments to print
 *
 * Return: number of bytes printed
 */
int p_chr(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
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
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * p_percent -  function prints character
 * @arg: pointer to argument(not usefull here) just technical
 * Return: number of bytes printed
 */
int p_percent(va_list arg)
{
	(void) arg;
	_putchar('%');
	return (1);
}
/**
 * p_di -  function prints integers
 * @arg: pointer to argument(not usefull here) just technical
 * Return: number of bytes printed
 */
int p_di(va_list args)
{
	int num, din = 1;
	unsigned int unum, count = 0;

	num = va_arg(args, int);
	if (num < 0)
	{
		count += _putchar('-');
		num = -1 * num;
	}
	else
		unum = num;
	while (unum / din > 9)
		din *= 10;
	while (unum != 0)
	{
		count += _putchar(unum / din + '0');
		unum %= din;
		din /= 10;
	}

	return (count);
}
