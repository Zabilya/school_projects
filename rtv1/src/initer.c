/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <cschuste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:34:01 by cschuste          #+#    #+#             */
/*   Updated: 2019/02/22 20:59:46 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

void	init_env(t_env *e)
{
	e->objs = (t_oc *)malloc(sizeof(t_oc));
	e->cam = (t_cam *)malloc(sizeof(t_cam));
	e->lit_var = (t_lc *)malloc(sizeof(t_lc));
	e->ren_var = (t_ren *)malloc(sizeof(t_ren));
	e->cam->rot = (t_v) {0, 0, 0};
	e->objs->n_obj = 0;
	e->cam->pos = (t_v) {0, 0, 0};
	e->cam->view_port_addr = 0x0;
	e->mlx = NULL;
	e->win = NULL;
	e->k = 0;
}

void	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "RTv1");
	e->cam->ptr_vp = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->cam->view_port_addr = (int *)mlx_get_data_addr(e->cam->ptr_vp,
		&e->cam->bits_per_pixel, &e->cam->size_line, &e->cam->endian);
}
