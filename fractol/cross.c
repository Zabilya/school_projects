/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:00:59 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/18 14:01:00 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_it(void *param)
{
	t_all *all;

	all = (t_all *)param;
	mlx_destroy_window(all->ptr->mlx, all->ptr->win);
	exit(1);
	return (0);
}
