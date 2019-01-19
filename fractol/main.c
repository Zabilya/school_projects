/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:49:41 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/09 14:49:41 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	another_fractal(t_all *all, char *frac)
{
	if (ft_strcmp(frac, "julia") == 0)
	{
		all->jul_po = (t_point *)malloc(sizeof(t_point));
		all->jul_po->x = 0;
		all->jul_po->y = 0;
		all->bound = 1;
		all->step = (double)2 / MAP_X;
		all->frac = 2;
	}
	else if (ft_strcmp(frac, "ship") == 0)
	{
		all->jul_po = (t_point *)malloc(sizeof(t_point));
		all->jul_po->x = 0;
		all->jul_po->y = 0;
		all->bound = 2;
		all->step = (double)4 / MAP_X;
		all->frac = 3;
	}
}

static	void	which_fractal(t_all *all, char *frac)
{
	if (ft_strcmp(frac, "mandelbrot") == 0 || ft_strcmp(frac, "ship")
		== 0 || ft_strcmp(frac, "tricorn") == 0
			|| ft_strcmp(frac, "mine") == 0)
	{
		all->jul_po = (t_point *)malloc(sizeof(t_point));
		all->jul_po->x = 0;
		all->jul_po->y = 0;
		all->bound = 2;
		all->step = (double)4 / MAP_X;
		if (ft_strcmp(frac, "mandelbrot") == 0)
			all->frac = 1;
		if (ft_strcmp(frac, "ship") == 0)
			all->frac = 3;
		if (ft_strcmp(frac, "tricorn") == 0)
			all->frac = 4;
	}
	else
		another_fractal(all, frac);
}

void			create_add_param(t_all *all, char *frac, int gpu)
{
	int		bpp;
	int		s_l;
	int		end;

	all->ptr->img = mlx_new_image(all->ptr->mlx, MAP_X, MAP_Y);
	all->img = (unsigned char *)mlx_get_data_addr(all->ptr->img,
		&bpp, &s_l, &end);
	all->start = (t_point *)malloc(sizeof(t_point));
	all->center = (t_point *)malloc(sizeof(t_point));
	which_fractal(all, frac);
	all->gpu = gpu;
	if (gpu == 0)
		all->max_iter = 100;
	else
		all->max_iter = 1000;
	all->center->x = 0;
	all->center->y = 0;
	all->zoom = 1;
	all->colour = 1;
	all->pause = 1;
}

static	void	main_for_fractal(char *frac, int gpu)
{
	t_all *all;

	all = (t_all *)malloc(sizeof(t_all));
	all->ptr = (t_ptr *)malloc(sizeof(t_ptr));
	all->ptr->mlx = mlx_init();
	all->ptr->win = mlx_new_window(all->ptr->mlx, MAP_X, MAP_Y, frac);
	create_add_param(all, frac, gpu);
	if (gpu)
		main_for_gpu(all);
	else
	{
		thread_use(all);
		mlx_mouse_hook(all->ptr->win, zoom, all);
		if (all->frac == 2)
			mlx_hook(all->ptr->win, 6, 0, julia_param, all);
		mlx_key_hook(all->ptr->win, rotate_and_destroy, all);
		mlx_hook(all->ptr->win, 17, 0, close_it, all);
		mlx_loop(all->ptr->mlx);
	}
}

int				main(int argc, char **argv)
{
	int	gpu;

	gpu = 1;
	if (argc != 2 && argc != 3)
	{
		ft_putendl(ABUSE);
		return (0);
	}
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "0") == 0)
			gpu = 0;
		else
		{
			ft_putendl("\tUsage: for run on CPU place 0 after fractal name");
			return (0);
		}
	}
	if (strcmp(argv[1], "mandelbrot") == 0 || strcmp(argv[1], "julia") == 0
		|| strcmp(argv[1], "ship") == 0 || strcmp(argv[1], "tricorn") == 0)
		main_for_fractal(argv[1], gpu);
	else
		ft_putendl(ABUSE);
	return (0);
}
