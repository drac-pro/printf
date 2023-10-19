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
/**
 * print_String - function prints custom specifier string
 * @args: argument to print
 *
 * Return: counter
 */
int print_String(va_list args)
{
	int i, count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		const char nullStr[] = "(null)";

		for (i = 0; nullStr[i] != '\0'; i++)
		{
			count += _putchar(nullStr[i]);
		}
		return (count);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar("0123456789ABCDEF"[(unsigned char) str[i] >> 4
					& 0xF]);
			count += _putchar("0123456789ABCDEF"[(unsigned char) str[i] & 0xF]);
		}
		else
		{
			count += _putchar(str[i]);
		}
	}

	return (count);
}
/**
 * print_address - function to print address of args.
 * @str: pointer to the address
 *
 * Return: count
 */
int print_address(void *str)
{
	unsigned long address = (unsigned long)str;

	int num_digits = sizeof(address) * 2;
	char hex_digits[] = "0123456789abcdef";

	int i, count = 0, digit;
	int leading_zeros = 1;

	for (i = num_digits - 1; i >= 0; i--)
	{
		unsigned long mask = 0xfUL << (i * 4);

		digit = (address & mask) >> (i * 4);
		
		if (digit == 0 && leading_zeros)
		{
			continue;
		}
		
		leading_zeros = 0;
		
		count += _putchar(hex_digits[digit]);
	}
	
	return (count);
}

/**
 * print_p - function to handle conversion specifier p
 * @args: argument to print
 *
 * Return: counter
 */
int print_p(va_list args)
{
	int count = 0;
	void *str = va_arg(args, void *);

	count += _putchar('0');
	count += _putchar('x');
	count += print_address(str);

	return (count);
}
