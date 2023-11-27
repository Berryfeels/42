/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:26:16 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/27 17:09:06 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dstcpy = (unsigned char *) dst;
	srccpy = (unsigned char *) src;
	i = 0;
	if (dstcpy > srccpy)
	{
		while (len-- > 0)
			dstcpy[len] = srccpy[len];
	}
	else 
	{
		while (i++ < len)
			dstcpy[i] = srccpy[i];
	}
	return (dst);
}
/*
#include <stdio.h>
#include <stddef.h>

int main()
{
	char source[] = "Hello, World!";
	char destination[20];

	// Using ft_memmove to copy from source to destination
	ft_memmove(destination, source, 13);

	// Printing the content of destination
	printf("Destination after ft_memmove: %s\n", destination);

	return 0;
}

*/