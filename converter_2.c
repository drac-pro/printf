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
/**
 * print_u - function prints unsigned interger
 * @args: unsigned number to print
 *
 * Return: number of bytes
 */
int print_u(va_list args)
{
	unsigned int num, i, j, temp, num_digits = 0, digit;
	int count = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
		count += _putchar('0');
	else
	{
		temp = num;
		while (temp > 0)
		{
			num_digits++;
			temp /= 10;
		}
		for (i = num_digits - 1; i > 0; i--)
		{
			unsigned int power = 1;

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
/**
 * print_o - function to handle specifier o.
 * @args: argument to print
 *
 * Return: number of bytes.
 */
int print_o(va_list args)
{
	unsigned int num, i, j, temp, num_digits = 0, digit;
	int count = 0;

	num = va_arg(args, unsigned int);

	if (num == 0)
		count += _putchar('0');
	else
	{
		temp = num;
		while (temp > 0)
		{
			num_digits++;
			temp /= 8;
		}

		for (i = num_digits; i > 0; i--)
		{
			unsigned int power = 1;

			for (j = 0; j < i; j++)
			{
				if (power > UINT_MAX / 8)
					break;
				power *= 8;
			}

			digit = num / power;
			count += _putchar(digit + '0');
			num -= digit * power;
		}
	}

	return (count);
}
/**
 * print_x_X - function to handle the hexadecimal specifier
 * @args: hexadecimal num to print
 *
 * Return: the number of bytes printed
 */
int print_x_X(va_list args)
{
	unsigned int i, j, num, temp, num_digits = 0, digit;
	char specifier = 'X';
	int uppercase = (specifier == 'X');
	int count = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
		count += _putchar('0');
	else
	{
		temp = num;
		while (temp > 0)
		{
			num_digits++;
			temp /= 16;
		}
	}

	for (i = num_digits; i > 0; i--)
	{
		unsigned int power = 1;

		for (j = 0; j < i; j++)
		{
			if (power > UINT_MAX / 16)
				break;
			power *= 16;
		}
		digit = num / power;
		if (digit < 10)
			count += _putchar(digit + '0');
		else
			count += _putchar(digit - 10 + (uppercase ? 'A' : 'a'));
		num -= digit * power;
	}
	return (count);
}
