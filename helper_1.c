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
	const char *x_chars = "0123456789abcdef";
	const char *X_chars = "0123456789ABCDEF";

	if (n / 16)
		count += p_xX_helper(n / 16, x);
	x == 'x' ? _putchar(x_chars[n % 16]) : _putchar(X_chars[n % 16]);
	count++;

	return (count);
}
