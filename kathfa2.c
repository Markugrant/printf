#include "main.h"

/* PRINT POINTER */

/**
* print_pointer - Prints value of pointer variable
* @types: arguments
* @width: width
* @flags:  Cal active flags
* @precision: Precision specification
* @buffer: Buffer array to handle print
* @size: Size specifier
* Return: printed chars
*/
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ka = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length = 2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(size);
	UNUSED(width);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ka--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ka++;

	/*return (write(1, &buffer[k], BUFF_SIZE - k - 1));*/
	return (write_pointer(buffer, ka, length,
		width, flags, padd, extra_c, padd_start));
}

/* PRINT NON PRINTABLE */

/**
* print_non_printable - Prints ascii codes in hexa of non printable chars
* @types: arguments
* @width: width
* @flags:  Cal active flags
* @precision: Precision specification
* @buffer: Buffer array to handle print
* @size: Size specifier
* Return: printed chars
*/
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[k] != '\0')
	{
		if (is_printable(str[k]))
			buffer[k + offset] = str[k];
		else
			offset += append_hexa_code(str[k], buffer, k + offset);
		k++;
	}
	buffer[k + offset] = '\0';
	return (write(1, buffer, k + offset));
}

/* PRINT REVERSE */

/**
* print_reverse - Prints string in reversed
* @types: arguments
* @width: width
* @flags: Cal active flags
* @precision: Precision specification
* @buffer: Buffer array to handle print
* @size: Size specifier
* Return: printed char
*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int k, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = "(NULL)";
	}
	for (k = 0; str[k]; k++)
	for (k - 1; k >= 0; k--)
	{
		char z = str[k];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/* PRINT A STRING IN ROT13 */

/**
* print_rot13string - Print string in rot13
* @types: arguments
* @width: width
* @flags:  Cal active flags
* @precision: Precision specification
* @buffer: Buffer array to handle print
* @size: Size specifier
* Return: printed chars
*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char w, *str;
	unsigned int k, d;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(flags);

	if (str == NULL)
		str = "(AHYY)";
	for (k = 0; str[k]; k++)
	{
		for (d = 0; in[d]; d++)
		{
			if (in[d] == str[k])
			{
				w = out[d];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[d])
		{
			w = str[k];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
