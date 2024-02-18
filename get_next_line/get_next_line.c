/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:24 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/18 19:15:40 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char ft_line_after_newline (const char *, int fd)
// {
//     create buffer;
//     malloc
//     print str in output;
// }
// char ft_line_before_newline (const char *, int fd)
// {

//     create buffer;
//     malloc
//     print str in output;
// }

char	*get_next_line(int fd)
{
	size_t	bytesread;
	static char *string; // the resulting text file
	// safe error buffer and read
	if (fd < 0 || /*BUFFER_SIZE <= 0 ||*/ read(fd, 0, 0) < 0)
		return (NULL);
	// while (str)
	// {
	//     // char ft_line_before_newline (const char *);
	//     // char ft_line_after_newline (const char *);
	// }
    string = ft_calloc(5, sizeof(char));
    if (!string)
        return (NULL);
	bytesread = read(fd, string, 4);
    if (bytesread <= 0)
        return (NULL);
	return (string);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
    while (1)
    {
        str = get_next_line(fd);
        if (str == NULL)
            break;
        printf("%s", str);
        str = NULL;
    }
	close(fd);
	return (0);
}
