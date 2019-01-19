NAME	=	fractol

SRC		=	main.c \
			algorythm.c \
			call_rotate.c \
			colour.c \
			mandelbrot.c \
			julia.c \
			ship.c \
			tricorn.c \
			gpu.c \
			draw_gpu_fractal.c \
			gpu_rotate.c \
			cross.c \

LIBFT	=	libft/

FW		=	-framework OpenGL -framework AppKit -framework OpenCL

MLX		=	minilibx_macos/

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
			make -C $(LIBFT)
			make -C $(MLX)
			gcc -o $@ $(FLAGS) $(SRC) -L$(LIBFT) -lft -L$(MLX) -lmlx $(FW)

clean:
			make -C $(LIBFT) clean
			make -C $(MLX) clean

fclean: clean
			rm $(NAME)
			make -C $(LIBFT) fclean

re: fclean all

go:
			gcc -o $(NAME) $(FLAGS) $(SRC) -lpthread -L$(LIBFT) -lft -L$(MLX) -lmlx $(FW)
