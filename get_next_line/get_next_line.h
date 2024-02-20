/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:10:30 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/20 18:20:30 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char *get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
char    *ft_get_line (char *buff);


#endif