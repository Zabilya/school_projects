/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:23:57 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/25 15:23:58 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_map *map, double degree)
{
	int		temp;
	double	x;
	double	y;

	temp = 0;
	while (temp < map->num_columns * map->num_raws)
	{
		x = map->points[temp]->x;
		y = map->points[temp]->y;
		map->points[temp]->x = x * cos(degree) - y * sin(degree);
		map->points[temp]->y = x * sin(degree) + y * cos(degree);
		temp++;
	}
}

void	rotate_y(t_map *map, double degree)
{
	int		temp;
	double	x;
	double	z;

	temp = 0;
	while (temp < map->num_columns * map->num_raws)
	{
		x = map->points[temp]->x;
		z = map->points[temp]->z;
		map->points[temp]->x = x * cos(degree) + z * sin(degree);
		map->points[temp]->z = z * cos(degree) - x * sin(degree);
		temp++;
	}
}

void	rotate_x(t_map *map, double degree)
{
	int		temp;
	double	y;
	double	z;

	temp = 0;
	while (temp < map->num_columns * map->num_raws)
	{
		y = map->points[temp]->y;
		z = map->points[temp]->z;
		map->points[temp]->y = y * cos(degree) - z * sin(degree);
		map->points[temp]->z = z * cos(degree) + y * sin(degree);
		temp++;
	}
}

void	one_more_rotation(int key, t_map *map)
{
	if (key == 88)
	{
		rotate_y(map, -ANGLE);
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else if (key == 69)
	{
		map->offset += map->offset * ZOOM;
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else if (key == 78)
	{
		map->offset -= map->offset * ZOOM;
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
}

void	another_rotation(int key, t_map *map)
{
	if (key == 91)
	{
		rotate_x(map, ANGLE);
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else if (key == 87)
	{
		rotate_x(map, -ANGLE);
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else if (key == 86)
	{
		rotate_y(map, ANGLE);
		mlx_clear_window(map->ptr->mlx_ptr, map->ptr->win_ptr);
		draw_line(map);
	}
	else
		one_more_rotation(key, map);
}
