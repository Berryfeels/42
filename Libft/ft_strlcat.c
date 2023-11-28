/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:04:30 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/28 19:44:03 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	sdst;
	unsigned int	ssrc;
	int				strsum;

	sdst = 0;
	ssrc = 0;
	while (dst[sdst] != '\0')
		sdst++;
	while (src[ssrc] != '\0')
		ssrc++;
	strsum = sdst + ssrc;
	ssrc = 0;
	while (src[ssrc] != '\0' && (sdst + ssrc) < (dstsize - 1))
	{
		dst[sdst + ssrc] = src[ssrc];
		ssrc++;
	}
	dst[sdst + ssrc] = '\0';
	return (strsum);
}
/*
#include <stdio.h>
int main() {
    char dst[] = "Hel";
    char src[] = "lo bitch!";
    unsigned int dstsize = 15;

    // Call your custom strlcat function
    unsigned int result = ft_strlcat(dst, src, dstsize);

    printf("Concatenated string: %s\n", dst);
    printf("Total length: %u\n", result);

    return 0;
}
*/
