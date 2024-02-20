/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:24 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/20 21:29:24 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char ft_string (int fd, char *string)
// {
//     string = ft_calloc(BUFFER_SIZE, sizeof(char));
//    if (!string)
//        return (NULL);
//     return (string);
    
// }

char *ft_get_line (int fd, char *buff)
{
    static char *rest = NULL;
    char *line;
    int i;
    int j;
    char *new_line;
    //buff attach to rest = draft;
    //from draft take out chars after '\n' and store it in rest.    
    i = 0;
    j = 0;
    buff = ft_calloc(BUFFER_SIZE , sizeof(char));
    if (!buff)
        return (NULL);
    while(buff)
    {
        if (*buff == '\n')
        *new_line;
        else 
            read(fd, buff, BUFFER_SIZE);
    }
        
    // char *draft = ft_strjoin(rest, buff);//attach buff to static char rest
    // while (*draft)
    // {
    //     if (*draft == '\n')
    //     {
    //         new_line = (char*) draft;
    //         i += 1;
    //         while(draft[i])
    //             {
    //                 rest[j] = draft[i];
    //             }
            
            
    //     }
    //     i++;
    //     *draft++;
    return (*new_line);   
}


       
    


char	*get_next_line(int fd)
{
    static char *buff;
   // char *draftline;
    //static char *string;
    size_t count;
    char *str;

    // the resulting text file
	// safe error buffer and read
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buff = ft_calloc(BUFFER_SIZE , sizeof(char));
    if (!buff)
        return (NULL);
    count = 1;
    while (count > 0)
    {
        count = read (fd, buff, BUFFER_SIZE);
        str = ft_get_line(fd, buff);
        if (count == 0)
            return(free(buff), NULL);
        return (str);
    }
    free(buff);
    return (NULL);
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
