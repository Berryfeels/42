/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:14:24 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/23 09:33:14 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *split_strings(char *draft_line, char delimiter, char *after_newline)
{
    char *delimiter_position;
    char *final_line;
    
    delimiter_position = ft_strchr(draft_line, '\n');// Trova la posizione del delimitatore nella stringa di input
        // Copia i dati nei buffer appena allocati
        ft_strncpy(*before_newline, draft_line, delimiter_position - draft_line);
        while 
        before_newline[delimiter_position] = '\0';

        strcpy(*after_newline, delimiter_position + 1); 

        return(final_line);
}

 
char *ft_get_line (int fd, char *buff, int count)
{
    static char *after_newline;
    char *before_newline;
    char *draft_line[BUFFER_SIZE];
    

    // new_buff = ft_calloc(BUFFER_SIZE , sizeof(char));
    // if (!new_uff)
    //     return (NULL);
   // memmove (draft_line, after_newline, BUFFER_SIZE);
    ft_memmove(after_newline, draft_line, ft_strlen(after_newline));
    if (ft_strchr(draft_line, '\n'))
    {
            ft_strlcat(draft_line, buff, BUFFER_SIZE);//copio il buff in una nuova stringa, se '\n' non viene trovato in buff viene scritta una nuova serie di BUFF_SIZE chars
                                 
                if (ft_strchr(draft_line, '\n'))//se non trovo il '\n' replico read e poi attacco il nuovo buff a draft_line
                {    
                    return(split_strings(draft_line, '\n', after_newline));
                    
                }
                else
                    count = read(fd, buff, BUFFER_SIZE);
    }
   free(new_buff);
        return(NULL);   
}
    


char	*get_next_line(int fd)
{
    char *buff;
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
        str = ft_get_line(fd, buff, count);
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
