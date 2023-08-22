#include "main.h"

/**
* _printf - Our custom printf function
* @format: The format string
* @...: The optional arguments
*
* Return: The number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%' && format[i + 1])
{
i++;
if (format[i] == 'c')
count += print_char(args);
else if (format[i] == 's')
count += print_string(args);
else if (format[i] == 'd' || format[i] == 'i')
count += print_int(args);
else if (format[i] == '%')
count += print_percent(args);
else
{
write(1, "%", 1);
count++;
}
}
else
{
write(1, &format[i], 1);
count++;
}
i++;
}

va_end(args);

return (count);
}
