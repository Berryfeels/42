# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 20:11:18 by stdi-pum          #+#    #+#              #
#    Updated: 2024/02/01 18:59:28 by stdi-pum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c \
			ft_print_char.c \
			ft_print_number.c \
			ft_print_string.c \
			ft_print_unsigned.c \
			ft_print_hexa.c\
			ft_itoa.c\
			ft_strlen.c\
OBJS			= $(SRCS:.c=.o)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= ft_printf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
