/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:51:29 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/01 18:22:37 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int ft_print_string(char *str, int *count)
{
    while (*str)
    {
        ft_print_char ((int)*str, count);
        ++str;
    }
    return (*count);
}
