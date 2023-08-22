#include "main.h"

/**
 * print_string - Print a string
 * @args: The va_list containing the string to print
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (str[count])
    {
        write(1, &str[count], 1);
        count++;
    }

    return count;
}
