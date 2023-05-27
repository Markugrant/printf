#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
*struct kdg - defines structure for symbols and functions
*@kdg: Operator
*@fa: function associated
*/
struct kdg
{
char *kdg;
int (*fa)(va_list, char[], int, int, int, int);
};
typedef struct kdg kdg_t;

/*Main functions*/
int handle_print(const char *kdg, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int _printf(const char *format, ...);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list list);
int print_hexa(va_list list);
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int rot13(va_list);
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);

/*Helper functions*/
char *_memcpy(char *dest, char *src, unsigned int n);
int is_printable(char);
int is_digit(char);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
