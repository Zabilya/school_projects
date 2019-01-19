/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:46:30 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/09 13:46:31 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <pthread.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"
# include <OpenCL/opencl.h>
# define BYTE 4
# define MAP_X 1024
# define MAP_Y 1024
# define ACCUR_MAN 4
# define ACCUR_JUL 4
# define ZOOM 0.2
# define THREADS 8
# define ABUSE "\tUsage: ./fractol mandelbrot \\ julia \\ ship \\ tricorn /0/"

typedef struct			s_ptr
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_ptr;

typedef	struct			s_point
{
	double				x;
	double				y;
}						t_point;

typedef	struct			s_some
{
	double				start_x;
	double				start_y;
	double				center_x;
	double				center_y;
	double				step;
	double				bound;
	double				zoom;
	double				jul_po_x;
	double				jul_po_y;
	char				*img;
	int					i;
	int					colour;
	int					max_iter;
}						t_some;

typedef	struct			s_all
{
	t_ptr				*ptr;

	t_point				*center;
	t_point				*start;
	t_point				*jul_po;
	double				step;
	double				bound;
	double				zoom;
	unsigned char		*img;
	int					frac;
	int					colour;
	int					pause;
	int					i;
	int					gpu;
	int					max_iter;
}						t_all;

typedef	struct			s_cl
{
	int					err;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				output;
	size_t				local;
	size_t				global;
}						t_cl;

typedef	struct			s_gpu
{
	t_all				*all;
	t_cl				*cl;
}						t_gpu;

void					*mandel_algo(void *arg);
void					*julia_algo(void *arg);
void					*ship_algo(void *arg);
void					*tricorn_algo(void *arg);
void					*myown_algo(void *arg);
void					thread_use(t_all *all);
void					choose_colour(t_some *some, int n, int i);
int						rotate_and_destroy(int key, void *param);
int						zoom(int button, int x, int y, void *param);
int						julia_param(int x, int y, void *param);
void					main_for_gpu(t_all *all);
int						gpu_zoom(int button, int x, int y, void *param);
int						gpu_julia_param(int x, int y, void *param);
int						gpu_destroy(int key, void *param);
void					draw_gpu_fractal(t_gpu *gpu);
int						close_it(void *param);
void					iterate(char *output,
						double center_x,
						double center_y,
						double bound,
						double step,
						int frac,
						int map_x,
						int map_y,
						int max_iter,
						int color,
						double jul_po_x,
						double jul_po_y);

#endif
