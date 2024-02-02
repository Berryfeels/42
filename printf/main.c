/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:56:46 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/01 17:58:43 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

int main (void)
{
    int count;
    void *ptr;

    // ft_printf("Hello %c\n", "e");
    // printf("Hello %c\n", "e");

    ft_printf("Hello %s\n", "John I love youza");
    printf("Hello %s\n", "John I love youza");

    // ft_printf ("The chars printed are %%d%i\n ",count);
    // printf("The chars printed are %%d %i\n",count);

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