NAME	=	fdf

SRC		=	main.c \
			read.c \
			call_rotate.c \
			rotate.c \
			draw.c \

LIBFT	=	libft/

GNL		=	gnl/get_next_line.c

FW		=	-framework OpenGL -framework AppKit

MLX		=	minilibx_macos/

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
			make -C $(LIBFT)
			make -C $(MLX)
			gcc -o $@ $(FLAGS) $(SRC) $(GNL) -L$(LIBFT) -lft -L$(MLX) -lmlx $(FW)

clean:
			make -C $(LIBFT) clean
			make -C $(MLX) clean

fclean: clean
			rm $(NAME)
			make -C $(LIBFT) fclean

re: fclean all