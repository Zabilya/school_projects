/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:31:09 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/11 13:31:10 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	g_i;
int	g_fd;
int g_square_size;

static	int		put_error(void)
{
	ft_putendl("error");
	return (0);
}

static	int		is_argc_valid(int argc)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_etrimino	*list;
	char		**map;

	g_square_size = 0;
	g_i = 0;
	list = NULL;
	if (!is_argc_valid(argc))
		return (0);
	g_fd = open(argv[1], O_RDONLY);
	list = read_tetriminos(g_fd, &g_square_size, &g_i);
	if (g_i == 1)
		return (put_error());
	g_square_size = calc_square(g_square_size * 4);
	map = create_map(g_square_size);
	while ((fillit(list, &g_square_size, &map, 0) == 0))
	{
		free_arr(&map);
		map = create_map(++g_square_size);
	}
	g_i = 0;
	while (map[g_i])
		ft_putendl(map[g_i++]);
	free_list(&list);
	free_arr(&map);
	return (0);
}
