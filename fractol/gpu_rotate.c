/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:40:48 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/17 15:40:49 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	move_all_up_down(int key, t_gpu *gpu)
{
	t_all	*all;

	all = gpu->all;
	if (key == 126)
	{
		all->center->y -= all->step * 30;
		draw_gpu_fractal(gpu);
	}
	else if (key == 125)
	{
		all->center->y += all->step * 30;
		draw_gpu_fractal(gpu);
	}
	else if (key == 123)
	{
		all->center->x -= all->step * 30;
		draw_gpu_fractal(gpu);
	}
	else if (key == 124)
	{
		all->center->x += all->step * 30;
		draw_gpu_fractal(gpu);
	}
}

static	void	cont_destroy(int key, t_gpu *gpu)
{
	t_all	*all;

	all = gpu->all;
	if (key == 69)
	{
		all->max_iter += 50;
		draw_gpu_fractal(gpu);
	}
	else if (key == 78)
	{
		all->max_iter -= 50;
		draw_gpu_fractal(gpu);
	}
	else if (key == 35)
		all->pause *= -1;
	else
		move_all_up_down(key, gpu);
}

int				gpu_destroy(int key, void *param)
{
	t_gpu	*gpu;
	t_all	*all;

	gpu = (t_gpu *)param;
	all = gpu->all;
	if (key == 53)
	{
		mlx_destroy_window(all->ptr->mlx, all->ptr->win);
		exit(1);
	}
	else if (key >= 83 && key <= 85)
	{
		if (key == 83)
			all->colour = 1;
		else if (key == 84)
			all->colour = 2;
		else
			all->colour = 3;
		draw_gpu_fractal(gpu);
	}
	else
		cont_destroy(key, gpu);
	return (0);
}

int				gpu_zoom(int button, int x, int y, void *param)
{
	t_gpu	*gpu;
	t_all	*all;

	gpu = (t_gpu *)param;
	all = gpu->all;
	if (button == 4 || button == 2 || button == 5)
	{
		all->center->x = all->center->x - all->bound + x * all->bound * 2
			/ MAP_X;
		all->center->y = all->center->y - all->bound + y * all->bound * 2
			/ MAP_Y;
	}
	if (button == 4 || button == 2)
	{
		all->bound -= all->bound * ZOOM;
		all->step -= all->step * ZOOM;
		draw_gpu_fractal(gpu);
	}
	else if (button == 5)
	{
		all->bound += all->bound * ZOOM;
		all->step += all->step * ZOOM;
		draw_gpu_fractal(gpu);
	}
	return (0);
}

int				gpu_julia_param(int x, int y, void *param)
{
	t_gpu	*gpu;
	t_all	*all;

	gpu = (t_gpu *)param;
	all = gpu->all;
	if (all->pause == 1)
	{
		all->jul_po->x = all->center->x - all->bound + x * all->bound * 2
			/ MAP_X;
		all->jul_po->y = all->center->y - all->bound + y * all->bound * 2
			/ MAP_Y;
		draw_gpu_fractal(gpu);
	}
	return (0);
}
