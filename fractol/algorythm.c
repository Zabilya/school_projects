/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:44:10 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/09 14:44:10 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	create_some(t_some **some, t_all *all)
{
	int i;

	i = 0;
	while (i < THREADS)
	{
		some[i] = (t_some *)malloc(sizeof(t_some));
		some[i]->img = (char *)malloc(MAP_X * MAP_Y * BYTE);
		some[i]->start_x = all->start->x;
		some[i]->start_y = all->start->y;
		some[i]->center_x = all->center->x;
		some[i]->center_y = all->center->y;
		some[i]->step = all->step;
		some[i]->bound = all->bound;
		some[i]->zoom = all->zoom;
		some[i]->colour = all->colour;
		some[i]->i = i;
		some[i]->max_iter = all->max_iter;
		if (all->frac == 2)
		{
			some[i]->jul_po_x = all->jul_po->x;
			some[i]->jul_po_y = all->jul_po->y;
		}
		i++;
	}
}

static	void	cont_thread(t_all *all, t_some **some, pthread_t *tid)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAP_X * MAP_Y * BYTE)
	{
		j = -1;
		while (++j < THREADS)
		{
			all->img[i + j * BYTE + 2] = some[j]->img[i + j * BYTE + 2];
			all->img[i + j * BYTE + 1] = some[j]->img[i + j * BYTE + 1];
			all->img[i + j * BYTE] = some[j]->img[i + j * BYTE];
		}
		i += THREADS * BYTE;
	}
	mlx_put_image_to_window(all->ptr->mlx, all->ptr->win, all->ptr->img, 0, 0);
	i = 0;
	while (i < THREADS)
	{
		free(some[i]->img);
		free(some[i++]);
	}
	free(some);
	free(tid);
}

void			thread_use(t_all *all)
{
	pthread_t	*tid;
	t_some		**some;
	int			i;

	i = -1;
	some = (t_some **)malloc(sizeof(t_some *) * THREADS);
	create_some(some, all);
	tid = (pthread_t *)malloc(sizeof(pthread_t) * THREADS);
	while (++i < THREADS)
	{
		if (all->frac == 1)
			pthread_create(&tid[i], NULL, mandel_algo, some[i]);
		else if (all->frac == 2)
			pthread_create(&tid[i], NULL, julia_algo, some[i]);
		else if (all->frac == 3)
			pthread_create(&tid[i], NULL, ship_algo, some[i]);
		else if (all->frac == 4)
			pthread_create(&tid[i], NULL, tricorn_algo, some[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(tid[i], NULL);
	cont_thread(all, some, tid);
}
