/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:14:36 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/22 19:34:01 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_src;
	char	*c_dst;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	c_src = (char *) src;
	c_dst = (char *) dst;
	i = 0;
	if (c_dst > c_src)
		while (len-- > 0)
			c_dst[len] = c_src[len];
	else
	{
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i ++;
		}
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*strcpy;

	strcpy = (unsigned char *)s;
	while (n > 0)
	{
		*strcpy++ = 0;
		n --;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*newstr;

	newstr = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	return (newstr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char ft_strcpy(char *str)
{
    char strcpy[0];
    int i;

    i = 0;
    while (*str)
    {
        strcpy[i] = str[i];
        i++; 
    }
    strcpy[i] = '\0';
    return(*strcpy);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ld;
	size_t	ls;
	char	*getlen;

	getlen = (char *) src;
	ls = ft_strlen(getlen);
	ld = ft_strlen(dst);
	if (ld >= size)
		ld = size;
	if (size == ld)
		return (ls + ld);
	if (size > (ls + ld))
		ft_memcpy(dst + ld, src, ls + 1);
	else
	{
		ft_memcpy(dst + ld, src, size - ld - 1);
		dst[size - 1] = '\0';
	}
	return (ld + ls);
}