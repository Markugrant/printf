#include "main.h"

/* PRINT CHAR */

/**
* print_char - prints char
* @types: arguments
* @buffer: buffer array to handle print
* @flags: cal active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* @Return:  printed chars
*/
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));

/* PRINT A STRING */

/**
* print_string - Prints string
* @types: arguments
* @buffer: Buffer array to handle print
* @flags: cal active flags
* @size: Size specifier
* @precision: Precision specification
* @width: Width
* @Return:  printed chars
*/
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, k;
	char *str = va_arg(types, char *);
	
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);
	UNUSED(buffer);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (k = width - length; k > 0; k--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (k = width - length; k > 0; k--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/* PRINT PERCENT SIGN */

/**
* print_percent - Prints percent sign
* @flags:  Cal active flags
* @precision: Precision specification
* @buffer: Buffer array to handle print
* @types: arguments
* @width: width
* @size: Size specifier
* Return: printed chars
*/
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(types);
	UNUSED(width);
	
	return (write(1, "%%", 1));
}

/* PRINT INT */

/**
* print_int - Prints integers
* @flags:  Cal active flags
* @precision: Precision specification
* @buffer: Buffer array to handle print
* @types: arguments
* @width: width
* @size: Size specifier
* Return: printed chars
*/
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	int is_negative = 0;
	long int d = va_arg(types, long int);
	unsigned long int num;
	
	d = convert_size_number(d, size);

	if (d == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)d;
	if (d < 0)
	{
		num = (unsigned long int)((-1) * d);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}
	k++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/*PRINT BINARY */

/**
* print_binary - Prints unsigned number
* @flags:  Cal active flags
* @precision: Precision specification
* @buffer: Buffer array to handle print
* @types: arguments
* @width: width
* @size: Size specifier
* Return: printed chars
*/
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int d, sum, g, k;
	unsigned int i[32];
	int count;

	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);

	d = va_arg(types, unsigned int);
	g = 2147483648; /* (2 ^ 31) */
	i[0] = d / g;
	for (k = 1; k < 32; k++)
	{
		g /= 2;
		i[k] = (d / g) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += i[k];
		if (sum || k == 31)
		{
			char z = '0' + i[k];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
