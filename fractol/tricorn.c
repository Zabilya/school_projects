/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:12:23 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/18 12:12:24 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	norme_vult(t_some *all, int *n, double *a, double *b)
{
	all->start_x = all->center_x - all->bound + all->step * (all->i % MAP_X);
	all->start_y = all->center_y - all->bound + all->step * (all->i / MAP_X);
	*n = 0;
	*a = all->start_x;
	*b = all->start_y;
}

void			*tricorn_algo(void *arg)
{
	t_some	*all;
	double	a;
	double	b;
	double	aa;
	int		counter;

	all = (t_some *)arg;
	while (all->i < MAP_X * MAP_Y)
	{
		norme_vult(all, &counter, &a, &b);
		while (counter < all->max_iter)
		{
			aa = a * a - b * b + all->start_x;
			b = -2 * a * b + all->start_y;
			a = aa;
			if (a * a + b * b > ACCUR_MAN)
				break ;
			counter++;
		}
		choose_colour(all, counter, all->i);
		all->i += THREADS;
	}
	pthread_exit(0);
	return (NULL);
}
