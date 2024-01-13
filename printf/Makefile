# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 13:45:22 by stdi-pum          #+#    #+#              #
#    Updated: 2024/01/13 13:46:35 by stdi-pum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_print.c ft_initialize.c
OBJS			= $(SRCS:.c=.o)

BONUS			=	
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
