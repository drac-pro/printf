#include "main.h"

int p_chr(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
int p_str(va_list args)
{
	int i;
	const char *str;

	str = va_arg(args, const char *);
	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
int p_percent()
{
	_putchar('%');
	return (1);
}
