/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:17:52 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/14 13:17:52 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	unsigned	char	*next_col(unsigned char *col, int n)
{
	if (n == 3)
	{
		col[0] = 211;
		col[1] = 236;
		col[2] = 248;
	}
	else if (n == 4)
	{
		col[0] = 248;
		col[1] = 201;
		col[2] = 95;
	}
	else if (n == 5)
	{
		col[0] = 153;
		col[1] = 87;
		col[2] = 0;
	}
	else if (n == 6)
	{
		col[0] = 176;
		col[1] = 10;
		col[2] = 10;
	}
	return (col);
}

static	unsigned	char	*colour_first(int n)
{
	unsigned	char	*col;

	col = (unsigned char *)malloc(3);
	n = n % 7;
	if (n == 0)
	{
		col[0] = 66;
		col[1] = 30;
		col[2] = 15;
	}
	else if (n == 1)
	{
		col[0] = 25;
		col[1] = 7;
		col[2] = 26;
	}
	else if (n == 2)
	{
		col[0] = 12;
		col[1] = 44;
		col[2] = 138;
	}
	else
		return (next_col(col, n));
	return (col);
}

static	unsigned	char	*colour_second(int n)
{
	unsigned	char	*col;

	col = (unsigned char *)malloc(3);
	col[0] = ((n % 16 + 1) * 16 + 1);
	col[1] = 0;
	col[2] = 0;
	return (col);
}

static	unsigned	char	*colour_third(int n)
{
	unsigned	char	*col;

	col = (unsigned char *)malloc(3);
	col[0] = 0;
	col[1] = 0;
	col[2] = (n * 16) % 255;
	return (col);
}

void						choose_colour(t_some *some, int n, int i)
{
	unsigned	char	*colour;

	if (some->colour == 1)
		colour = colour_first(n);
	else if (some->colour == 2)
		colour = colour_second(n);
	else
		colour = colour_third(n);
	if (n == some->max_iter)
	{
		some->img[i * BYTE + 2] = 0;
		some->img[i * BYTE + 1] = 0;
		some->img[i * BYTE + 0] = 0;
	}
	else
	{
		some->img[i * BYTE + 2] = colour[0];
		some->img[i * BYTE + 1] = colour[1];
		some->img[i * BYTE + 0] = colour[2];
	}
	free(colour);
}
