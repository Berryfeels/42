/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:01:45 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/01 18:58:16 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **env)
{
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
	if (argc == 0)
		ft_printf("ciola");//placeholder for bullshit
	
	while (1)
	{	
	

		prompt = readline("Simon says> ");
		if (prompt)
		{
			if(*prompt)
			{
				add_history(prompt);
				ft_printf("The string prompt is: %s\n", prompt);//checker
				if (prompt[0] == 'c' && prompt[1] == 'd' && prompt[2] == ' ')
				{
					buff = ft_substr(prompt, 3, strlen(prompt)); 
					chdir(buff);
					free(buff);
				}
				if (prompt[0] == 'p' && prompt[1] == 'w' && prompt[2] == 'd')
				{
					char path [_PC_PATH_MAX];
					char pwd[3] = "pwd";
					//p1 = fork();
					//if (p1 < 0)
					//	return (2);
					getcwd(path,_PC_PATH_MAX);
					ft_printf("%s\n", path);
					ft_dprintf("cacca ");
					//if (p1 == 0)
						execute(pwd, env);
					//waitpid(p1, NULL, 0);
					ft_dprintf("cacca");
					
					
				}
				
				if (strncmp(prompt, "exit", 4) == 0)//cancel after, placeholder to exit
				{
					free(prompt);
					return 0;
				}
				free (prompt);
			}
		}
		else 
			break;
		
	}
	return 0;
}