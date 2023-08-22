#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Print a character
 * @args: Variadic argument list
 * @count: Pointer to the character count
 */
void print_char(va_list args, int *count)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    (*count)++;
}

/**
 * print_string - Print a string
 * @args: Variadic argument list
 * @count: Pointer to the character count
 */
void print_string(va_list args, int *count)
{
    char *s = va_arg(args, char *);
    int i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        (*count)++;
        i++;
    }
}

/**
 * print_int - Print an integer
 * @args: Variadic argument list
 * @count: Pointer to the character count
 */
void print_int(va_list args, int *count)
{
    int num = va_arg(args, int);
    int temp = num;
    int digits = 0;
    int index;
    char buffer[20];

    if (temp == 0)
    {
        buffer[0] = '0';
        write(1, buffer, 1);
        (*count)++;
        return;
    }

    if (num < 0)
    {
        write(1, "-", 1);
        (*count)++;
        temp = -temp;
    }

    while (temp != 0)
    {
        buffer[digits] = temp % 10 + '0';
        temp /= 10;
        digits++;
    }

    for (index = digits - 1; index >= 0; index--)
    {
        write(1, &buffer[index], 1);
        (*count)++;
    }
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variadic arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
                print_char(args, &count);
            else if (*format == 's')
                print_string(args, &count);
            else if (*format == 'd' || *format == 'i')
                print_int(args, &count);
            else if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, format - 1, 2);
                count += 2;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
