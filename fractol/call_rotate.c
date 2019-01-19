/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:56:23 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/27 19:56:24 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	move_all_up_down(int key, t_all *all)
{
	if (key == 126)
	{
		all->center->y -= all->step * 30;
		thread_use(all);
	}
	else if (key == 125)
	{
		all->center->y += all->step * 30;
		thread_use(all);
	}
	else if (key == 123)
	{
		all->center->x -= all->step * 30;
		thread_use(all);
	}
	else if (key == 124)
	{
		all->center->x += all->step * 30;
		thread_use(all);
	}
}

static	void	cont_rotate(int key, t_all *all)
{
	if (key == 69)
	{
		all->max_iter += 50;
		thread_use(all);
	}
	else if (key == 78)
	{
		all->max_iter -= 50;
		thread_use(all);
	}
	else if (key == 35)
		all->pause *= -1;
	else
		move_all_up_down(key, all);
}

int				rotate_and_destroy(int key, void *param)
{
	t_all	*all;

	all = (t_all *)param;
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
		thread_use(all);
	}
	else
		cont_rotate(key, all);
	return (0);
}

int				zoom(int button, int x, int y, void *param)
{
	t_all	*all;

	all = (t_all *)param;
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
		thread_use(all);
	}
	else if (button == 5)
	{
		all->bound += all->bound * ZOOM;
		all->step += all->step * ZOOM;
		thread_use(all);
	}
	return (0);
}

int				julia_param(int x, int y, void *param)
{
	t_all *all;

	all = (t_all *)param;
	if (all->pause == 1)
	{
		all->jul_po->x = all->center->x - all->bound + x * all->bound * 2
			/ MAP_X;
		all->jul_po->y = all->center->y - all->bound + y * all->bound * 2
			/ MAP_Y;
		thread_use(all);
	}
	return (0);
}
