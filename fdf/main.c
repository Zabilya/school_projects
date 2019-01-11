/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:42:29 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/24 14:42:30 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_points(t_map *map)
{
	int		i;
	int		j;
	int		num_points;

	i = 0;
	num_points = map->num_raws * map->num_columns;
	map->points = (t_point **)malloc(sizeof(t_point *) * num_points);
	num_points = 0;
	while (i < map->num_raws)
	{
		j = 0;
		while (j < map->num_columns)
		{
			map->points[num_points] = (t_point *)malloc(sizeof(t_point));
			map->points[num_points]->x = j - map->pic_center->x;
			map->points[num_points]->y = i - map->pic_center->y;
			map->points[num_points]->z = map->arr[i][j];
			++num_points;
			++j;
		}
		i++;
	}
}

void	find_add_param(t_map *map)
{
	int		x;
	int		y;

	x = map->num_columns;
	y = map->num_raws;
	if (x > 450 || y > 250)
		map->offset = 2;
	else if (x > 210 || y > 110)
		map->offset = 5;
	else if (x > 50 || y > 20)
		map->offset = 10;
	else
		map->offset = 20;
	map->map_raws = (map->num_raws + 30) * map->offset;
	map->map_columns = (map->num_columns + 30) * map->offset;
	map->pic_center->x = map->num_columns / 2;
	map->pic_center->y = map->num_raws / 2;
	map->center->x = map->map_columns / 2;
	map->center->y = map->map_raws / 2;
}

void	main_for_read(char *file)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->ptr = (t_ptr *)malloc(sizeof(t_ptr));
	map->center = (t_point *)malloc(sizeof(t_point));
	map->pic_center = (t_point *)malloc(sizeof(t_point));
	if (!(read_file(file, map)))
	{
		ft_putendl("Error");
		exit(0);
	}
	find_add_param(map);
	create_points(map);
	map->ptr->mlx_ptr = mlx_init();
	map->ptr->win_ptr = mlx_new_window(map->ptr->mlx_ptr, map->map_columns,
		map->map_raws, "window");
	draw_line(map);
	mlx_key_hook(map->ptr->win_ptr, rotate_and_destroy, map);
	mlx_loop(map->ptr->mlx_ptr);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf map");
		return (0);
	}
	main_for_read(argv[1]);
}
