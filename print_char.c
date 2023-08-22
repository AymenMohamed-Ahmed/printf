#include "main.h"

/**
 * print_char - Print a character
 * @args: The va_list containing the character to print
 *
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);

    write(1, &c, 1);
    return 1;
}
