/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:56:41 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/01 16:59:13 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void print_unsigned(unsigned int n, int *count)
{
    char str;

    str = ft_itoa(n);
    count = ft_strlen(str);
    free(str);
    *count++;
}
