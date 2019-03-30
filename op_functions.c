#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
/**
 *_putchar - print a character
 *@c: char
 *Return: ascci character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *printchar - execute the print
 *@str: va_list object
 *Return: a pointer to the correct function
 */
int printchar(va_list str)
{
	char string;

	string = (char)va_arg(str, int);
	_putchar(string);
	return (1);
}
/**
 *printstring - print string
 *@str: string
 *Return: a pointer to the correct function
 */
int printstring(va_list str)
{
	int a = 0;
	char *nu = "(null)";
	char *string = va_arg(str, char*);

	if (!string)
	{
		for ( ; *(nu + a) ; a++)
			_putchar(nu[a]);
		return (a);
	}
	for (a = 0 ;  string[a] ; a++)
		_putchar(string[a]);
	return (a);
}
/**
 *printdigit - print number
 *@str: string
 *Return: a pointer to the correct function
 */
int printdigit(va_list str)
{
	int count, num;

	count = 0;
	num = va_arg(str, int);
	count += recursive_pt(num);
	return (count);
}
/**
 * recursive_pt - recursive print
 * @num: number param.
 *
 * Return: counter.
 */
int recursive_pt(int num)
{
	int count = 0;
	unsigned int x = num;

	if (num < 0)
	{
		count += _putchar('-');
		x = -x;
	}
	if (x / 10)
		count += recursive_pt(x / 10);
	count += _putchar(x % 10 + '0');
	return (count);
}
/**
 *print_binary - print binary of a decimal number
 *@str: string
 *Return: the number of elelemnts printed
 */
int print_binary(va_list str)
{
	int count;
	unsigned int num;

	count = 0;
	num = va_arg(str, unsigned int);
	count += printbinary(num);
	return (count);
}
/**
 * printbinary - prints the binary representation of a number.
 * @n: given number in decimal to convert
 * Return: the number of elements printed
 */
int printbinary(unsigned int n)
{
	int bit, bin = 0, count = 0;

	for (bit = 31; bit >= 0; bit--)
	{
		bin = n >> bit & 1;
		if (bin == 1)
			break;
		if (bit == 0 && bin == 0)
		{
			_putchar('0');
			return (1);
		}
	}
	for (; bit >= 0; bit--)
	{
		bin = n >> bit & 1;
		_putchar(bin + '0');
		count++;
	}
	return (count);
}
