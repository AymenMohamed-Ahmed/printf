#include "main.h"
#include <stdlib.h>

/**
 * print_int - Print an integer
 * @args: The va_list containing the integer to print
 *
 * Return: The number of characters printed
 */
int print_int(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    char *buffer;

    if (num < 0)
    {
        write(1, "-", 1);
        count++;
        num = -num;
    }

    if (num == 0)
    {
        write(1, "0", 1);
        count++;
    }
    else
    {
        int temp = num;
        int digits = 0;

        while (temp)
        {
            temp /= 10;
            digits++;
        }

        buffer = (char *)malloc(digits + 1);
        if (!buffer)
            return -1;

        buffer[digits] = '\0';

        while (digits > 0)
        {
            digits--;
            buffer[digits] = num % 10 + '0';
            num /= 10;
        }

        write(1, buffer, sizeof(buffer) - 1);
        count += sizeof(buffer) - 1;

        free(buffer);
    }

    return count;
}
