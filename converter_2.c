#include "main.h"

/**
 * p_b -  function prints binary
 * @args: pointer to argument(not usefull here) just technical
 * Return: number of bytes printed
 */
int p_b(va_list args)
{
	unsigned int num = va_arg(args, int);
	int count;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	count = print_binary(num);
	return (count);
}
/**
 * print_binary - ...
 * @n: number
 *
 * Return: number of bytes
 */
int print_binary(unsigned int n)
{
	int count = 0;

	if (n == 0)
		return (0);
	count += print_binary(n >> 1);
	_putchar('0' + (n & 1));
	count++;
	return (count);
}

