/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:37:30 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/14 16:37:30 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	norme_vult(t_some *all, int *n)
{
	all->start_x = all->center_x - all->bound + all->step * (all->i % MAP_X);
	all->start_y = all->center_y - all->bound + all->step * (all->i / MAP_X);
	*n = 0;
}

void			*julia_algo(void *arg)
{
	t_some		*all;
	double		a;
	double		b;
	int			counter;

	all = (t_some *)arg;
	while (all->i < MAP_X * MAP_Y)
	{
		norme_vult(all, &counter);
		while (counter < all->max_iter)
		{
			a = all->start_x;
			b = all->start_y;
			all->start_x = a * a - b * b + all->jul_po_x;
			all->start_y = 2 * a * b + all->jul_po_y;
			if (a * a + b * b > ACCUR_JUL)
				break ;
			counter++;
		}
		choose_colour(all, counter, all->i);
		all->i += THREADS;
	}
	pthread_exit(0);
	return (NULL);
}
