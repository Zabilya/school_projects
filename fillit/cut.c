/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:31:09 by emayert           #+#    #+#             */
/*   Updated: 2018/12/17 13:31:10 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_xmin;
int	g_xmax;
int	g_ymin;
int	g_ymax;

static	char	**arrmalloc(int wid, int len)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * wid + 1);
	while (i < wid)
		arr[i++] = (char *)malloc(len + 1);
	arr[wid] = NULL;
	return (arr);
}

static	void	calc_mins(int *g_xmin, int *g_ymin, char **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*g_xmin = 4;
	*g_ymin = 4;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if (arr[i][j] != '.')
			{
				if (i < *g_xmin)
					*g_xmin = i;
				if (j < *g_ymin)
					*g_ymin = j;
			}
			++j;
		}
		j = 0;
		++i;
	}
}

static	void	calc_maxs(int *g_xmax, int *g_ymax, char **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*g_xmax = 0;
	*g_ymax = 0;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if (arr[i][j] != '.')
			{
				if (j > *g_ymax)
					*g_ymax = j;
				if (i > *g_xmax)
					*g_xmax = i;
			}
			++j;
		}
		j = 0;
		++i;
	}
}

char			**trunc_arr(char **arr, int *raw, int *column)
{
	char	**tet;
	int		i;
	int		j;

	calc_mins(&g_xmin, &g_ymin, arr);
	calc_maxs(&g_xmax, &g_ymax, arr);
	*raw = g_xmax - g_xmin + 1;
	*column = g_ymax - g_ymin + 1;
	tet = arrmalloc(g_xmax - g_xmin + 1, g_ymax - g_ymin + 1);
	i = 0;
	while (g_xmin <= g_xmax)
	{
		j = 0;
		while (g_ymin <= g_ymax)
		{
			tet[i][j] = arr[g_xmin][g_ymin];
			++j;
			++g_ymin;
		}
		g_ymin -= j;
		++i;
		++g_xmin;
	}
	return (tet);
}
