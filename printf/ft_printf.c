/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:23:42 by stefanodipu       #+#    #+#             */
/*   Updated: 2024/02/02 19:25:16 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be pprintf.c:48:9: warning: implicit declaration of function 'ft_print_unsigned' is invalid in C99 [-Wimplicit-function-declaration]
        ft_print_unsigned((va_arg (ap, unsigned int)), count);rinted in hexadecimal format. 
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/
int ft_print_char(char c, int *count)
{
    write(1, &c, 1); 
    return (*++count);
}

int ft_print_string(char *str, int *count)
{
    while (*str)
    {
        ft_print_char ((int)*str, count);
        str++;
    }
    return (*count);
}

int ft_print_hexa(long n, char specifier, int *count)//I cast to long as, wanting to use recursion, I avoid overflow problems when I change to positive a negative number (in order to work with it)
{
    char *symbols;

    count = 0;
    if ( specifier == 'x')
        symbols = "0123456789abcdef";
    else if (specifier == 'X')
        symbols = "0123456789ABCDEF";
    if (n < 16) // for the hexadecimal
        ft_print_char(symbols[n], count); //la cosa figa e che in questo caso n e in posizione n nella stringa symbols
    else
    {
        ft_print_hexa(n/16, specifier, count);
        ft_print_hexa(n%16, specifier, count);
    }
    return (*count);
}

char	*ft_writestring(char *str, long int n, int count, int sign)
{
	str[count--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[count] = (n % 10) + 48;
		n /= 10;
		count --;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

int	ft_count(long int number)
{
	int	count;

	count = 0;
	if (number <= 0)
	{
		number *= -1;
		count++;
	}
	while (number > 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	number;
	char		*str;
	int			sign;
	int			count;
	long int	tmp;

	number = n;
	if (number < 0)
		tmp = number * -1;
	else
		tmp = number;
	sign = 0;
	if (number < 0)
		sign = 1;
	count = ft_count(number);
	number = tmp;
	str = (char *)malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_writestring(str, number, count, sign);
	return (str);
}

int	ft_strlen(char str)
{
	int	i;

	i = 0;
	while (str++)
	{
		i++;
	}
	return (i);
}

int ft_print_number(int n, int *count)
{    
    char *str = ft_itoa(n);
    if (!(str))
        return (-1);
    ft_print_char(*str, count);
    free (str);
    return (*count);
}

int ft_print_unsigned(unsigned int n, int *count)
{
    char *str = ft_itoa(n);
    if (!(str))
        return (-1);
    *count = ft_strlen(*str);
    ft_print_char(*str, count);
    free (str);
    return (*count);
}

int ft_print_format(const char specifier, va_list ap, int *count)
{
    if (specifier == 'c')//a char
        ft_print_char(va_arg (ap, int), count);//type promotion is happening, it means small value variables like char, 
                                    //when passed to a variadic funciton, as they are not known before, 
                                    //are promoted to int. So in this case, the char value has become an int value
    else if (specifier == 's')//a string
        ft_print_string(va_arg (ap, char *), count);
    else if (specifier == 'p')//The void * pointer argument has to be printed in hexadecimal format. 
    {
        write (1, "0x", 2);
        ft_print_hexa((long)(va_arg (ap, void *)), 'x', count);
    }
    else if (specifier == 'd' || specifier == 'i')//digit int
        ft_print_number((va_arg (ap, int)), count);//long casting explained at the function. I can use this function to print both digits and hexadecimals
    else if (specifier == 'u')// %u Prints an unsigned decimal (base 10) number.
        ft_print_unsigned((va_arg (ap, unsigned int)), count);
    else if (specifier == 'x' || specifier == 'X')//digit hexadecimal lowercase and UPPERCASE
        ft_print_hexa((va_arg (ap, unsigned int)), specifier, count);// 10 and 16 are the base system, unsigned int because 
                                                                    //hexadecimal representation never show minus. (having a 1 for example, all bits of the int are on :8 bits, the hexa  for 1 is ffffffff, which is the same as for -1)
    else if (specifier == '%')
        write (1, "%", 1);
    else 
        return(-1);
    return (*count);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     count;

    count = 0;
    va_start(ap, format);
    while (*format)
    {
        if (*format == '%')
            count += ft_print_format(*++format, ap, &count); // unary operator '++'has precedence (from right to left)
        else if (*format == '\0')
            return (-1);
        else
            count += write (1, format, 1);
        
        ++format;
    }
    va_end(ap);
    return(count);
}

int main (void)
{
    int count;
    void *ptr;

    count = ft_printf("%d\n",900);
    ft_printf("The number of char printed is %d\n",count);

    // ft_printf("Hello %s\n", "John I love youza");
    // printf("Hello %s\n", "John I love youza");

    // count = ft_printf ("The number is %d\n ", 42);
    // ft_printf("The chars printed are %d\n", count);

    // ft_printf ("The chars printed are %%x%x\n", count);
    // printf("The chars printed are %%X%X\n", count);

    // ft_printf ("The chars printed are %%x %x\n", '?');
    // printf("The chars printed are %%X%X\n", '?');

    // ft_printf ("The number is %%i%i\n", (2147483648));
    // printf("The number is %%i%i\n", (2147483647));

    // ft_printf ("The number is %%u%u, count is:%d\n", (INT_MIN), count);
    // printf("The number is %%u%u, count is:%d\n", (INT_MIN), count);

    // ft_printf ("The number is %%X%X\n", (INT_MAX));
    // printf("The number is %%X%X\n", (INT_MAX));

    // printf("the count %%i%i\n", count);
    // ft_printf ("the count %%i%i\n", count);

    return (0);
}