#include "main.h"

/**
 * passer - helper function for _printf this function loops through the format
 *	string printing the characters and calls the respective function to
 *	handle a specifier when it meets one.
 * @format: pointer to format string
 * @args: va_list pointer to variable arguments to be printed
 * @specs: pointer to a list of specifiers
 * Return: number of bytes(characters) printed
 */
int passer(const char *format, spec_f specs[], va_list args)
{
	int i, j = 0, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			/* inner loop to handle format specifiers */
			for (j = 0; specs[j].spec != 0; j++)
			{
			if (format[i + 1] == specs[j].spec)
			{
				count += specs[j].f(args);
				break;
			}
			}
			if (specs[j].spec == 0)
			{
			if (format[i + 1] != '\0')
			{
				count += str_error(format[i + 1]);
			}
			else
				return (-1);
			}
			i++;
		}
		else
		{
			/* prints character if it's not a '%' */
			_putchar(format[i]);
			count++;
		}
	}
	return (count);
}

/**
 * _printf - print a formatted text to stdout
 *
 * @format: pointer to a format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int count;
	va_list args;
	spec_f specs[] = {
		{'c', p_chr},
		{'s', p_str},
		{'%', p_percent},
		{'d', p_di},
		{'i', p_di},
		{'b', p_b},
		{'u', print_u},
		{'o', print_o},
		{'x', print_x},
		{'X', print_X},
		{'S', print_S},
		{'p', print_p},
		{0, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = passer(format, specs, args);
	va_end(args);

	flush_buffer();

	return (count);
}
