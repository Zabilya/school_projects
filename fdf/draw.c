/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:43:10 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/24 14:43:10 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	abuse_norm(int *delta, int *x_y, int *sign, int *er)
{
	*er -= *delta;
	*x_y += *sign;
}

static	void	draw_this_line(int x1, int y1, t_map *map)
{
	int		delta_x;
	int		delta_y;
	int		sign_x;
	int		sign_y;
	int		error;

	delta_x = abs(map->x2 - x1);
	delta_y = abs(map->y2 - y1);
	sign_x = x1 < map->x2 ? 1 : -1;
	sign_y = y1 < map->y2 ? 1 : -1;
	error = delta_x - delta_y;
	while (x1 != map->x2 || y1 != map->y2)
	{
		mlx_pixel_put(map->ptr->mlx_ptr, map->ptr->win_ptr, x1, y1, COL);
		map->temp = error * 2;
		if (map->temp > delta_y * -1)
			abuse_norm(&delta_y, &x1, &sign_x, &error);
		if (map->temp < delta_x)
		{
			error += delta_x;
			y1 += sign_y;
		}
	}
}

static	void	create_x_y(int *x, int *y, int i, t_map *map)
{
	*x = map->points[i]->x * map->offset + map->center->x;
	*y = map->points[i]->y * map->offset + map->center->y;
}

void			draw_line(t_map *map)
{
	t_point	**po;
	int		x1;
	int		y1;
	int		i;

	po = map->points;
	i = map->num_columns * map->num_raws - 1;
	while (i >= 0)
	{
		create_x_y(&x1, &y1, i, map);
		if (i % map->num_columns != 0)
		{
			create_x_y(&map->x2, &map->y2, i - 1, map);
			draw_this_line(x1, y1, map);
		}
		if (i >= map->num_columns)
		{
			create_x_y(&map->x2, &map->y2, i - map->num_columns, map);
			draw_this_line(x1, y1, map);
		}
		i--;
	}
}
