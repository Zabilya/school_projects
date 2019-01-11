/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:47:16 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/14 16:47:22 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_etrimino **list)
{
	t_etrimino *temp;

	temp = *list;
	if (temp->next)
		free_list(&temp->next);
	temp->next = NULL;
	free_arr(&temp->tetrimino);
	free(temp->tetrimino);
	temp->tetrimino = NULL;
	free(temp);
}

char	**create_map(int square_side)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * square_side + 1);
	while (i < square_side)
	{
		map[i] = (char *)malloc(square_side + 1);
		j = 0;
		while (j < square_side)
			map[i][j++] = '.';
		map[i][j] = '\0';
		++i;
	}
	map[i] = NULL;
	return (map);
}

char	**copy_map(char **map, int square_side)
{
	char	**copy;
	int		i;
	int		j;

	copy = (char **)malloc(sizeof(char *) * square_side + 1);
	i = 0;
	while (i < square_side)
	{
		copy[i] = (char *)malloc(square_side + 1);
		j = 0;
		while (j < square_side)
		{
			copy[i][j] = map[i][j];
			++j;
		}
		copy[i][j] = '\0';
		++i;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_arr(char ***arr)
{
	char	**temp;
	int		i;

	i = 0;
	temp = *arr;
	while (temp[i])
		free(temp[i++]);
	temp[0] = NULL;
}

int		calc_square(int tetr_num)
{
	int n;

	n = 2;
	while (n * n < tetr_num)
		++n;
	return (n);
}
