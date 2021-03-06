/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <cschuste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:26:12 by cschuste          #+#    #+#             */
/*   Updated: 2019/03/07 15:18:59 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

static	void	create_light(t_env *e)
{
	e->lnum = 2;
	e->light = (t_light **)malloc(sizeof(t_light *) * e->lnum);
	e->light[1] = (t_light *)malloc(sizeof(t_light));
	e->light[1]->type = "ambient";
	e->light[1]->intensity = 0.1;
	e->light[0] = (t_light *)malloc(sizeof(t_light));
	e->light[0]->type = "point";
	e->light[0]->intensity = 0.9;
	e->light[0]->pos = (t_v){8, 0, 8};
}

void			create_scene_2(t_env *e)
{
	int		i;

	i = -1;
	e->objs->n_obj = 2;
	e->objs->objarr = (t_obj **)malloc(sizeof(t_obj *) * e->objs->n_obj);
	while (++i < e->objs->n_obj)
		e->objs->objarr[i] = (t_obj *)malloc(sizeof(t_obj));
	i = -1;
	cr_obj((t_bs){0, 4, 0, 0, -1, 0, 0, 40, 80, 250, 0, 0, 0, T_PLANE}, ++i, e);
	cr_obj((t_bs){0, 0, 20, 0, -1, 0, 0.6, 150, 150, 0, 0, 0, 0, T_CONE}, ++i, e);
	create_light(e);
}
