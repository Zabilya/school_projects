NAME = 	fillit
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror -I libft/

SRC	=	cut.c \
		add.c \
		fillit.c \
		main.c \
		read.c

OBJ	= 	$(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	gcc -g $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all