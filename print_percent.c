#include "main.h"

/**
 * print_percent - Print a percent character
 * @args: The va_list (unused)
 *
 * Return: The number of characters printed (always 1)
 */
int print_percent(va_list args)
{
    (void)args;

    write(1, "%", 1);
    return 1;
}
