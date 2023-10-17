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
	int num, i, temp, num_digits = 0, digit;
	int count = 0;

	num = va_arg(args, int);
	if (num == 0)
		count += _putchar('0');
	else
	{
	if (num < 0)
	{
		count += _putchar('-');
		num = num * -1;
	}
	temp = num;
	while (temp > 0)
	{
		num_digits++;
		temp /= 10;
	}
	for (i = num_digits - 1; i >= 0; i--)
	{
		int j, power = 1;

		for (j = 0; j < i; j++)
		{
			power *= 10;
		}
		digit = num / power;
		count += _putchar(digit + '0');
		num -= digit * power;
	}
	}
	return (count);
}
