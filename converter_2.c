#include "main.h"

/**
 * print_u - function prints unsigned interger
 * @args: unsigned number to print
 * @flags: bitmask int representing flags to be processed
 * @length: int representing length modifier
 *
 * Return: number of bytes
 */
int print_u(va_list args, int flags, int length)
{
	unsigned long num = length_modifier(args, length);

	(void) flags;
	return (p_diou_helper(num, 10));
}
/**
 * print_o - function to handle specifier o.
 * @args: argument to print
 * @flags: bitmask int representing flags to be processed
 * @length: int representing length modifier
 *
 * Return: number of bytes.
 */
int print_o(va_list args, int flags, int length)
{
	unsigned long num = length_modifier(args, length);
	int count = 0;

	/*handling the '#' flag*/
	if (flags & HASH_FLAG && num != 0)
		count += _putchar('0');
	count += p_diou_helper(num, 8);

	return (count);
}
/**
 * print_x - function to handle the hexadecimal specifier
 * @args: hexadecimal num to print
 * @flags: bitmask int representing flags to be processed
 * @length: int representing length modifier
 *
 * Return: the number of bytes printed
 */
int print_x(va_list args, int flags, int length)
{
	unsigned long num = length_modifier(args, length);
	int count = 0;

	/*handling the '#' flag*/
	if (flags & HASH_FLAG && num != 0)
	{
		count += _putchar('0');
		count += _putchar('x');
	}
	count += p_xX_helper(num, 'x');

	return (count);
}
/**
 * print_X - function to handle the 'X' hexadecimal specifier
 * @args: hexadecimal num to print
 * @flags: bitmask int representing flags to be processed
 * @length: int representing length modifier
 *
 * Return: the number of bytes printed
 */
int print_X(va_list args, int flags, int length)
{
	unsigned long num = length_modifier(args, length);
	int count = 0;

	/*handling the '#' flag*/
	if (flags & HASH_FLAG && num != 0)
	{
		count += _putchar('0');
		count += _putchar('X');
	}
	count += p_xX_helper(num, 'X');

	return (count);
}
