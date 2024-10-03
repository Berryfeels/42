/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:01:45 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/03 13:11:32 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_openErrorScan(void)
{
	int fd;
	
	fd = open ("ErrorScan.txt", O_RDWR, O_CREAT, 0777);
	if (fd == -1)
		close (fd);
		exit (EXIT_ERROR);
}

int	main()
{	//int argc, char **argv, char **env
	//maneggiare argv
	//se cd non pipare
	//fare subito
	//cd puo solo stare all'inizio
	int	fd;
	char *prompt;
	char *buff;
	//pid_t	p1;

	
	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}
	ft_openErrorScan;
	// if (argc == 0)
	// 	ft_printf("ciola");//placeholder for bullshit
	// if (argv[1])	
	// 	ft_printf("La vecchina patatina");
	
	while (1)
	{	
	

		prompt = readline("Mestepum> ");
		if (prompt)
		{
			if(*prompt)
			{
				add_history(prompt);
				if (prompt[0] == 'c' && prompt[1] == 'd' && prompt[2] == ' ')
				{
					buff = ft_substr(prompt, 3, strlen(prompt)); 
					chdir(buff);
					free(buff);
				}
				if (prompt[0] == 'p' && prompt[1] == 'w' && prompt[2] == 'd')
				{
				
					char cwd[PATH_MAX];
					if (getcwd(cwd, PATH_MAX) == NULL)
     					 perror("getcwd() error");
    				else
      					printf("%s\n", cwd);	
					
				}
				
				if (strncmp(prompt, "exit", 4) == 0)//cancel after, placeholder to exit
				{
					ft_exit();
		
				}
				free (prompt);
			}
		}
		else 
			break;
		
	}
	close (fd);
	return 0;
}