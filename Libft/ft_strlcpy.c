/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:18:56 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/27 19:28:46 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (src[j] != '\0' || j < (dstsize - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i - 1);
}

// #include <stdio.h>
// int main() {
//     char destination[] = "cacca";
//     const char source[] = "Hello, World!";
// 	unsigned int dstsize = 2;
//     // Call your custom strlcpy function
//     size_t result = strlcpy(destination, source, dstsize);

//     // Print the copied string and the return value
//     printf("Copied string: %s\n", destination);
//     printf("Total length: %lu\n", result);

//     return 0;
// }
