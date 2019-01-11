/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:44:46 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/14 10:44:47 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_ti;
int	g_tj;
int	g_ai;
int	g_aj;

static	void	init_g(void)
{
	g_ti = 0;
	g_tj = 0;
	g_ai = 0;
	g_aj = 0;
}

static	void	write_tetr(char **tetr, char ***map, int si, int sj)
{
	char	**arr;

	init_g();
	arr = *map;
	while (tetr[g_ti])
	{
		while (tetr[g_ti][g_tj])
		{
			if (tetr[g_ti][g_tj] == '.')
			{
				++g_tj;
				++g_aj;
				continue;
			}
			arr[g_ai + si][g_aj++ + sj] = tetr[g_ti][g_tj++];
		}
		g_tj = 0;
		g_aj = 0;
		++g_ti;
		++g_ai;
	}
}

static int		put_tetrimino(t_etrimino *list, char ***map, int si, int sj)
{
	char	**temp;
	int		i;
	int		j;

	temp = *map;
	i = 0;
	while (i < list->raw)
	{
		j = 0;
		while (j < list->column)
		{
			if (list->tetrimino[i][j] != '.' && temp[si + i][sj + j] != '.')
				return (0);
			++j;
		}
		++i;
	}
	write_tetr(list->tetrimino, map, si, sj);
	return (1);
}

static	void	del_tetr(char **tetr, char ***map, int si, int sj)
{
	char	**arr;

	init_g();
	arr = *map;
	while (tetr[g_ti])
	{
		while (tetr[g_ti][g_tj])
		{
			if (tetr[g_ti][g_tj] == '.')
			{
				++g_tj;
				++g_aj;
				continue;
			}
			arr[g_ai + si][g_aj++ + sj] = '.';
			g_tj++;
		}
		g_tj = 0;
		g_aj = 0;
		++g_ti;
		++g_ai;
	}
}

int				fillit(t_etrimino *list, int *side, char ***map, int num)
{
	int		si;
	int		sj;

	if (list == NULL)
		return (1);
	si = 0;
	while (si <= *side - list->raw)
	{
		sj = 0;
		while (sj <= *side - list->column)
		{
			if (put_tetrimino(list, map, si, sj))
			{
				if (fillit(list->next, side, map, num))
					return (1);
				else
					del_tetr(list->tetrimino, map, si, sj);
			}
			++sj;
		}
		++si;
	}
	return (0);
}
