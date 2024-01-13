/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:39:25 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/01/13 13:46:37 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_print *ft_initialise_tab(t_print *tab)                       
{                       
      tab->wdt = 0;        // we set everything to 0, false        
      tab->prc = 0;                        
      tab->zero = 0;                        
      tab->pnt = 0;                        
      tab->sign = 0;                        
      tab->tl = 0;                        
      tab->is_zero = 0;                        
      tab->dash = 0;                        
      tab->perc = 0;                        
      tab->sp = 0;                        
      return (tab);                       
}

int ft_printf(const char *format, ...)
{
   t_print *tab;
                       
   tab = (t_print *)malloc(sizeof(t_print));                        
   if (!tab)                         
       return (-1);
   ft_initialise_tab(tab)
}

