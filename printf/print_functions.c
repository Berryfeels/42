/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:53:43 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/09 21:42:34 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_char(char c, int *count)
{
    write(1, &c, 1); 
   //printf("Value of COUNT is now: %p\n", count);
    return (*count)++;
}

int ft_print_string(char *str, int *count)
{
    if (!str)
	{
		str = "(null)";
	}
    while (*str)
    {
        ft_print_char (*str, count);
        str++;
    }
    return (*count);
}

int ft_print_hexa(unsigned long n, char specifier, int *count)//I cast to long as, wanting to use recursion, I avoid overflow problems when I change to positive a negative number (in order to work with it)
{
    char *symbols;

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

int ft_print_number(int n, int *count)
{    
    char *str = ft_itoa(n);
    if (!(str))
        return (-1);
    ft_print_string(str, count);
    free (str);
    return (*count);
}

int ft_print_unsigned(unsigned int n, int *count)
{
    if (n >= 10)
		ft_print_unsigned(n / 10, count);
	ft_print_char(n % 10 + '0', count);
    return (*count);
}

int ft_print_pointer(void *ptr, int *count)
{
    unsigned long   ptr_address;

    if (!ptr)
        return (ft_print_string("(nil)", count));
    ft_print_string("0x", count);
    ptr_address = (unsigned long) ptr;
    ft_print_hexa(ptr_address, 'x', count);
    return (*count);
}