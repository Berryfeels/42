/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:04:34 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/28 20:10:54 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		num;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	sign = 0;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign ++;
		++str;
	}
	num = 0;
	while (*str && *str >= 48 && *str <= 57)
	{
		num *= 10;
		num += *str - 48;
		++ str;
	}
	if (sign % 2)
		return (-num);
	return (num);
}
// #include <stdio.h>
// int main (void)
// {
// 	char *number = "  +--++38ojkj";
// 	printf("The number is: %d", ft_atoi(number));
// 	return (0);
// }
