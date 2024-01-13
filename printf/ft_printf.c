/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:18:43 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/01/13 13:47:05 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int printf(const char *format, ...)
{
    va_list ap;
    int     count;

    va_start(ap, format);
    count = 0;
    while (*format != '\0')
        if (*format == %)
            printformat(*(++format)); 
}