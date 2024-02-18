/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:14:36 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/18 15:49:05 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s)
{
	int		ls;
	char	*ptr;
	int		i;

	ls = ft_strlen ((char *)s);
	ptr = (char *) malloc ((ls + 1) * sizeof(const char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ls)
	{
		ptr[i] = s[i];
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
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
