CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_isalpha.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c
OBJS=$(SRCS:.c=.o)
NAME=libft.a

all:	$(NAME)
%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Creating library $@"
.PHONY:	clean
clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
