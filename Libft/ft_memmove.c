/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:26:16 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/20 16:58:51 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;
	int				i;
	dstcpy = (unsigned char*)dst;
	srccpy = (unsigned char*)src;

	i = 0;
	while (len > 0)
	{
		dstcpy[i] = srccpy[i+2];
		i ++;
		len --; 
	}
	return(dst);
}
#include <stdio.h>
int main() {
	char src [5]= {'a', 'b', 'c', 'd'};
	char dest[5];

	// Using ft_memcpy to copy from src to dest
	ft_memmove(dest, src, 5);

	// Printing the content of dest
	printf("Destination after ft_memmove: %s\n", dest);

	return 0;
}