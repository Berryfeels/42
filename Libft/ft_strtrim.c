/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:55:48 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/02 18:07:10 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parameters
// s1: The string to be trimmed.
// set: The reference set of characters to trim.
// Return value
// The trimmed string.
// NULL if the allocation fails.
// External functs. malloc
// Description
// The ft_strtrim() function takes a string and trims it.
// Trimming means removing the characters specified in the set string
// from the start AND from the end of the string s1, without removing what's
//in the middle of s1.
// From s1 "ababaaaMy name is Simonbbaaabbad" we want to remove every a and
// b from the start and the end of s1, keeping the stuff in the middle of s1.
// the result is "My name is Simone"

//get length s1;
	//loop while iterate through s1 from Start (s1[0])
	//while (s1[i] == (set[y++]) && set[y] == '\0'))
	//int start = 0; start ++;
	//loop while iterate through s1 from End (s1[len--])
	//if (s1[len] == (set[y++] until set[y] == '\0'))
	//malloc buffer will be = len - n.
	//malloc create a buffer for new string resulting from ft_strtrim.
	//copy s1[n++]  in buffer till n < len

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		y;
	int		i;
	size_t	len;
	char	*strim;
	size_t	n;

	start = 0;
	y = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		{
			while (s1[i] == set[y] && set[y] != '\0')
				y ++;
		}
		i ++;
		y = 0;
	}
	while (s1[i] != '\0')
		i ++;
	while (s1[i] > 0)
	{
		{
			while (s1[i] == set[y] && set[y] != '\0')
				y ++;
		}
		i ++;
		y = 0;
	}
strim = (char *) malloc ((i - n) * sizeof(char const))
if(strim == NULL)
	return(NULL)
*ft_memcpy(strim, s, (len - n));
return (strim);
}
