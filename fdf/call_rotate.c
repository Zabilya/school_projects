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

#include "fdf.h"

void		move_map_right_left(int key, t_map *map)
{
	if (key == 123)
	{
		map->center->x -= 15;
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else if (key == 124)
	{
		map->center->x += 15;
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else
		another_rotation(key, map);
}

void		move_map_up_down(int key, t_map *map)
{
	if (key == 126)
	{
		map->center->y -= 15;
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else if (key == 125)
	{
		map->center->y += 15;
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else
		move_map_right_left(key, map);
}

int			rotate_and_destroy(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == 53)
	{
		mlx_destroy_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		exit(1);
	}
	else if (key == 89)
	{
		rotate_z(map, ANGLE);
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else if (key == 92)
	{
		rotate_z(map, -ANGLE);
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else
		move_map_up_down(key, map);
	return (0);
}
