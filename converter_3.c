#include "main.h"

/**
 * print_HEXA - function to handle the 'X' hexadecimal specifier
 * @args: hexadecimal num to print
 *
 * Return: the number of bytes printed
 */
int print_HEXA(va_list args)
{
	unsigned int i, j, num, temp, num_digits = 0, digit;
	int count = 0;

	int uppercase = 1;

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

		for (i = num_digits; i < 8; i++)
		{
			count += _putchar(uppercase ? '0' : 'f');
		}
		for (i = num_digits; i > 0; i--)
		{
			unsigned int power = 1;

			for (j = 1; j < i; j++)
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
	}
	return (count);
}