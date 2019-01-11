/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:23:56 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/24 10:23:57 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define ZOOM 0.1
# define ANGLE 0.087
# define COL 0x00FF00

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptr;

typedef	struct	s_map
{
	t_point		**points;
	t_point		*center;
	t_point		*pic_center;
	t_ptr		*ptr;
	double		offset;
	int			**arr;
	int			num_raws;
	int			num_columns;
	int			map_raws;
	int			map_columns;
	int			temp;
	int			x2;
	int			y2;
}				t_map;

void			draw_line(t_map *map);
int				rotate_and_destroy(int key, void *param);
int				read_file(char *file, t_map *map);
void			rotate_z(t_map *map, double degree);
void			rotate_y(t_map *map, double degree);
void			rotate_x(t_map *map, double degree);
void			one_more_rotation(int key, t_map *map);
void			another_rotation(int key, t_map *map);

#endif
