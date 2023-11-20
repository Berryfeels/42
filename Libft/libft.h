/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:10:39 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/19 13:38:36 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include "stddef.h"
int ft_isalpha(char a);
int ft_isdigit(int arg);
int ft_isalnum(int argument);
int	ft_strlen(char *str);
void *ft_memset(void *str, int c, size_t n);
int	ft_isprint(int arg);
int	ft_isascii(int c);

#endif