/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:40:46 by stefanodipu       #+#    #+#             */
/*   Updated: 2024/02/27 14:24:38 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			flag;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buff[0] || read(fd, buff, BUFFER_SIZE) > 0))
	{
		line = ft_strjoin_get_next_line(line, buff);
		i = 0;
		j = 0;
		while (buff[i])
		{
			if (flag == 1)
				buff[j++] = buff[i];
			if (buff[i] == '\n')
				flag = 1;
			buff[i++] = 0;
		}
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("file.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			break ;

// 		printf("- %s", str);
// 		str = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }
