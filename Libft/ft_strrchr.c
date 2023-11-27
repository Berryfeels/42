/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:00:37 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/23 19:15:35 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *) &s[i]);
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i --;
	}
	return (NULL);
}
