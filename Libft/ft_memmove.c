/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:26:16 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/20 19:40:51 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;
	unsigned char	temp[len];
	int				i;

	dstcpy = (unsigned char*)dst;
	srccpy = (unsigned char*)src;
	i = 0;
	while (i < len)
	{
		temp[i] = srccpy[i];
		i ++;
	}
	i = 0;
	while (i < len)
	{
		dstcpy[i] = temp[i];
		i ++; 
	}
	return(dst);
}
#include <stdio.h>
int main() {
    char source[] = "Hello, World!";
    char destination[10];

    // Using ft_memmove to copy from source to destination
    ft_memmove(destination, source, 5);

    // Printing the content of destination
    printf("Destination after ft_memmove: %s\n", destination);

    return 0;
}