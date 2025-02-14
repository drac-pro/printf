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
 * p_di - function prints integers
 * @args: pointer to argument(not usefull here) just technical
 * Return: number of bytes printed
 */
int p_di(va_list args)
{
	int count = 0, num = va_arg(args, int);
	unsigned int n;

	/* handling negative integers*/
	if (num < 0)
	{
		count += _putchar('-');
		n = -num;
	}
	else
		n = num;
	count += p_diou_helper(n, 10);

	return (count);
}
/**
 * p_b -  function prints binary
 * @args: pointer to argument(not usefull here) just technical
 * Return: number of bytes printed
 */
int p_b(va_list args)
{
	unsigned int num = va_arg(args, int);

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	return (print_binary(num));
}
