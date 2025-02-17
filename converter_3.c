#include "main.h"

/**
 * print_S - function prints custom specifier string
 * @args: argument to print
 * @flags: bitmask int representing flags to be processed
 *
 * Return: counter
 */
int print_S(va_list args, int flags)
{
	int i, count = 0;
	const char *hex_digits = "0123456789ABCDEF";
	char *str = va_arg(args, char *);

	(void) flags;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		/*printing hexadecimal equivalent of unprintable characters*/
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			/*converting each 4bits to hex equivalent*/
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
 * print_p - function to handle conversion specifier p
 * @args: argument to print
 * @flags: bitmask int representing flags to be processed
 *
 * Return: counter
 */
int print_p(va_list args, int flags)
{
	int count = 0;
	void *ptr = va_arg(args, void *);

	(void) flags;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count += _putchar('0');
	count += _putchar('x');
	count += print_address(ptr);

	return (count);
}
