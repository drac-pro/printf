#include "main.h"

/**
 * p_diou_helper - Recursively print digits of a number
 * @n: Unsigned number to print
 * @base: base of the number to be printed
 * Return: Number of digits printed
 */
int p_diou_helper(unsigned int n, int base)
{
	int count = 0;

	if (n / base)
		count += p_diou_helper(n / base, base);
	_putchar(n % base + '0');
	count++;

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
	/* divide by two using binary right shift */
	/*recursion unwind cause first call to print last digit*/
	count += print_binary(n >> 1);
	/* print least significan bit*/
	_putchar('0' + (n & 1));
	count++;
	return (count);
}
/**
 * p_xX_helper - Recursively print digits of a hexadecimal number
 * @n: unsigned number to print
 * @x: character specifying lower or uppercase hex number
 * Return: number of hex digits printed
 */
int p_xX_helper(unsigned int n, char x)
{
	int count = 0;
	const char *hex_chars = x == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";

	if (n / 16)
		count += p_xX_helper(n / 16, x);
	_putchar(hex_chars[n % 16]);
	count++;

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
	int num_digits = sizeof(void *) * 2;
	const char hex_digits[] = "0123456789abcdef";
	int i, count = 0, start = 0, digit;

	for (i = num_digits - 1; i >= 0; i--)
	{
		digit = (address >> (i * 4)) & 0xF;
		/*handles leading zeros and edge case of 0x0*/
		if (digit || start || i == 0)
		{
			count += _putchar(hex_digits[digit]);
			start = 1;
		}
	}
	return (count);
}
