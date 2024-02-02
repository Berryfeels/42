/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:02:05 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/01 18:52:23 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int ft_print_hexa(unsigned long n, char specifier, int *count)//I cast to long as, wanting to use recursion, I avoid overflow problems when I change to positive a negative number (in order to work with it)
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