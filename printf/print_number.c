/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:45:17 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/01 17:00:51 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int print_number(int n, int *count)
{
    char *str;
    
    str = *ft_itoa (str);
    count = ft_strlen(&str);
    free(str);
    return (*count);
}