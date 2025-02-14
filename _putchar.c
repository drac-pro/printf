#include "main.h"

/**
 * _putchar - stores characters in a buffer which are then written to stdout
 * @c: character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static int index;

	/* condition to flush the buffer */
	/* optimizes performance */
	if (c == -1 || index >= BUFFER_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}
	/* store chars in buffer so write is called less frequent*/
	if (c != -1)
		buffer[index++] = c;

	return (1);
}
/**
 * flush_buffer - manually flushes the buffer
 */
void flush_buffer(void)
{
	_putchar(-1);
}
