#include "main.h"

/**
 * length_modifier - modifies the length of an arg based on the length
 * @args: variable arg to modify the length
 * @length: int representing length modifier
 * Return: modified length casted to unsigned long for compatibility
 */
unsigned long length_modifier(va_list args, int length)
{
	if (length == LENGTH_LONG)
		return (va_arg(args, unsigned long));
	else if (length == LENGTH_SHORT)
		return ((unsigned short)va_arg(args, unsigned int));
	return (va_arg(args, unsigned int));
}
