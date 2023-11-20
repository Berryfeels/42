CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_isalpha.c
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
