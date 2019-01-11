/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:42:51 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/24 14:42:52 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		count_lines(int fd)
{
	int		file;
	int		lines;
	char	ch;

	lines = 0;
	while ((file = read(fd, &ch, 1)))
	{
		if (ch == '\n')
			lines++;
	}
	return (lines);
}

static	int		*create_num(char **arr, t_map *map)
{
	int	*temp;
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (arr[counter])
		++counter;
	if (map->num_columns != 0 && counter > map->num_columns)
		return (NULL);
	map->num_columns = counter;
	temp = (int *)malloc(sizeof(int) * map->num_columns);
	while (i < map->num_columns)
	{
		temp[i] = ft_atoi(arr[i]);
		++i;
	}
	return (temp);
}

int				read_file(char *file, t_map *map)
{
	int		fd;
	int		i;
	int		**arr;
	char	*line;
	char	**temp;

	map->num_columns = 0;
	map->num_raws = 0;
	fd = open(file, O_RDONLY);
	map->num_raws = count_lines(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	arr = (int **)malloc(sizeof(int *) * map->num_raws);
	i = 0;
	while (i < map->num_raws)
	{
		get_next_line(fd, &line);
		temp = ft_strsplit(line, ' ');
		if (!(arr[i] = create_num(temp, map)))
			return (0);
		i++;
	}
	map->arr = arr;
	return (1);
}
