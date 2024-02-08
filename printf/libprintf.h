/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:41:56 by jadyar            #+#    #+#             */
/*   Updated: 2024/02/08 21:13:10 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>

char	*ft_itoa(int n);
int	ft_printf(const char *format, ...);
int main (void);
void	ft_print_char(char c, int *count);
int	ft_print_string(char *str, int *count);
int	ft_print_p(void *ptr, int *count);
void	ft_print_d(int nb, int *count);
void	ft_print_unsigned(unsigned int n, int *count);
int ft_print_hexa(unsigned long n, char specifier, int *count);
size_t	ft_strlen(const char *str);
int	ft_printf(const char *format, ...);
int	ft_print_number(int n, int *count);

#endif
