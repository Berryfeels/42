/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:04:30 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/30 18:45:46 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ld;
	size_t	ls;
	char	*getlen;

	getlen = (char *) src;
	ls = ft_strlen(getlen);
	ld = ft_strlen(dst);
	while (dst[ld] != '\0')
		ld++;
	while (src[ls] != '\0' && ld + ls < dstsize - 1)
	{
		dst[ld + ls] = src[ls];
		ls++;
	}
	dst[ld + ls] = '\0';
	while (src[ls] != '\0')
		ls++;
	return (ld + ls);
}

#include <stdio.h>
int main() {
    char dst[10];
    char src[] = "lorem ipsum dolor sit amet";
    unsigned int dstsize = 2;

    unsigned int result = ft_strlcat(dst, src, dstsize);

    printf("Concatenated string: %s\n", dst);
    printf("Total length: %u\n", result);

    return 0;
}
