#include "main.h"

/**
 * print_S - function prints custom specifier string
 * @args: argument to print
 *
 * Return: counter
 */
int print_S(va_list args)
{
	int i, count = 0;
	const char *hex_digits = "0123456789ABCDEF";
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar(hex_digits[(unsigned char) str[i] >> 4]);
			count += _putchar(hex_digits[(unsigned char) str[i] & 0xF]);
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
 * @ptr: pointer to the address
 *
 * Return: count
 */
int print_address(void *ptr)
{
	unsigned long address = (unsigned long)ptr;
	/*num of hex digits need to print the address 32bit => 8 / 64bit => 16*/
	int num_digits = sizeof(void*) * 2;
	const char hex_digits[] = "0123456789abcdef";
	int i, count = 0, start = 0, digit;

	for (i = num_digits - 1; i >= 0; i--)
	{
		digit = (address >> (i * 4)) & 0xF;
		if (digit || start || i == 0)
		{
			count += _putchar(hex_digits[digit]);
			start = 1;
		}
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
	void *ptr = va_arg(args, void *);

	if (!ptr)
		return (write(1, "(nil)", 5));
	count += _putchar('0');
	count += _putchar('x');
	count += print_address(ptr);

	return (count);
}
