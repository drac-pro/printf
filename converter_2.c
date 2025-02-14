#include "main.h"

/**
 * print_u - function prints unsigned interger
 * @args: unsigned number to print
 *
 * Return: number of bytes
 */
int print_u(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (p_diou_helper(num, 10));
}
/**
 * print_o - function to handle specifier o.
 * @args: argument to print
 *
 * Return: number of bytes.
 */
int print_o(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (p_diou_helper(num, 8));
}
/**
 * print_x - function to handle the hexadecimal specifier
 * @args: hexadecimal num to print
 *
 * Return: the number of bytes printed
 */
int print_x(va_list args)
{
	unsigned int num =  va_arg(args, unsigned int);

	return (p_xX_helper(num, 'x'));
}
/**
 * print_X - function to handle the 'X' hexadecimal specifier
 * @args: hexadecimal num to print
 *
 * Return: the number of bytes printed
 */
int print_X(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (p_xX_helper(num, 'X'));
}
