#include "main.h"

/**
 * passer - helper function for _printf this function loops through the format
 * 	    string printing the characters and calls the respective function to
 * 	    handle a specifier when it meets one.
 * @format: pointer to format string
 * @args: va_list pointer to variable arguments to be printed
 *
 * Returns: number of bytes(characters) printed
 */
int passer(const char *format, va_list args)
{
	int i, j, count;
	spec_f specs[] = {
		{'c', p_chr},
		{'s', p_str},
		{'%', p_percent},
		{0, NULL}
	};
	
	j = 0, count = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			while (specs[j].spec != 0)
			{
			if (format[i + 1] == specs[j].spec)
			{
				count += specs[j].f(args);
			}
			j++;
			}
			j = 0, i++;
		}
		else
		{
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

	if (format == NULL)
		return (-1);

	va_start(args, format);
        count = passer(format, args);
	return (count);
}
