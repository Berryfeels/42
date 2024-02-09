/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:52:07 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/09 21:43:02 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main (void)
{
    int count;
    void *ptr;
    
    ptr = NULL;
    count = ft_printf("%d\n",900);
    ft_printf("The number of char printed is %d\n",count);
    count = printf("%d\n", 900);
    printf("The number of char printed is %d\n",count);

    count = ft_printf("Hello %s\n", "John I love youza");
    ft_printf("The count is %d\n", count);

    count = printf("%x\n", -1);
    ft_printf ("The count is (%%d) %d\n", count);
    count = printf("%x\n", -1);
    printf("The count is (%%d) %d\n", count);

    count = ft_printf("%p\n", ptr);
    ft_printf("The pointer is at the address: %p and count is %d\n", ptr, count);
    count = printf("%p\n", ptr);
    printf("The pointer is at the address: %p and count is %d\n", ptr, count);


    ft_printf ("The number is %%i: %i\n", (2147483647));
    printf("The number is %%i: %i\n", (2147483647));

    count = ft_printf("%%%s\n", ""); 
    ft_printf ("The number is %% u %u, count is:%d\n", (INT_MIN), count);
    count = printf("%%%s\n", ""); 
    printf("The number is %% u %u, count is:%d\n", (INT_MIN), count);

    return (0);
}