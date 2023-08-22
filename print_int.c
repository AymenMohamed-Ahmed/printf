#include "main.h"

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
int digits = count_digits(num);
buffer = generate_buffer(num, digits);

write(1, buffer, digits);
count += digits;

free(buffer);
}

return (count);
}

/**
* count_digits - Count the number of digits in an integer
* @num: The integer to count digits for
*
* Return: The number of digits
*/
int count_digits(int num)
{
int count = 0;
while (num)
{
num /= 10;
count++;
}
return (count);
}

/**
* generate_buffer - Generate a string buffer for an integer
* @num: The integer to generate buffer for
* @digits: The number of digits in the integer
*
* Return: The generated buffer
*/
char *generate_buffer(int num, int digits)
{
char *buffer = (char *)malloc(digits + 1);
if (!buffer)
return (NULL);

buffer[digits] = '\0';

while (digits > 0)
{
digits--;
buffer[digits] = num % 10 + '0';
num /= 10;
}

return (buffer);
}
