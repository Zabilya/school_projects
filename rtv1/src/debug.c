/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <emayert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 01:23:45 by emayert           #+#    #+#             */
/*   Updated: 2019/02/22 20:35:21 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

/*
**	Reacts on precoded key presses.
*/

static	void	key_handler2(int key, t_env *e)
{
	if (key == K_NUM_4)
		e->cam->rot.y -= M_PI / 180 * 15;
	else if (key == K_NUM_6)
		e->cam->rot.y += M_PI / 180 * 15;
	if (key == K_NUM_2)
		e->cam->rot.x -= M_PI / 180 * 15;
	else if (key == K_NUM_8)
		e->cam->rot.x += M_PI / 180 * 15;
	if (key == K_NUM_7)
		e->cam->rot.z -= M_PI / 180 * 15;
	else if (key == K_NUM_9)
		e->cam->rot.z += M_PI / 180 * 15;
}

void			key_handler(int key, t_env *e)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_ARRUP)
		e->cam->pos.y -= 1;
	if (key == K_ARRDOWN)
		e->cam->pos.y += 1;
	if (key == K_ARRLEFT)
		e->cam->pos.x -= 1;
	if (key == K_ARRIGHT)
		e->cam->pos.x += 1;
	if (key == K_NUM_PLUS)
		e->cam->pos.z += 2;
	if (key == K_NUM_MINUS)
		e->cam->pos.z -= 2;
	key_handler2(key, e);
}
