/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:44:34 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/10 10:44:35 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	g_i;
int	g_ccount;

char		**create_tetrimino(char *buff, int counter)
{
	char	**tetrimino;
	int		raw;
	int		j;

	g_i = 0;
	raw = 0;
	tetrimino = (char **)malloc(sizeof(char *) * 5);
	while (g_i < 4)
	{
		tetrimino[g_i] = (char *)malloc(5);
		j = -1;
		while (++j < 4)
		{
			if (buff[raw] == '.')
				tetrimino[g_i][j] = buff[raw];
			if (buff[raw] == '#')
				tetrimino[g_i][j] = (char)(counter + 65);
			++raw;
		}
		tetrimino[g_i++][j] = '\0';
		++raw;
	}
	tetrimino[g_i] = NULL;
	return (tetrimino);
}

void		create_object(t_etrimino **obj, char *buff, int counter)
{
	t_etrimino	*list;
	char		**temp;

	list = *obj;
	list->raw = 0;
	list->column = 0;
	list->next = NULL;
	temp = create_tetrimino(buff, counter);
	list->tetrimino = temp;
	temp = trunc_arr(list->tetrimino, &(list->raw), &(list->column));
	free_arr(&list->tetrimino);
	list->tetrimino = temp;
}

void		create_list(t_etrimino **list, char *buff)
{
	t_etrimino	*temp;
	int			counter;

	if (*list == NULL)
	{
		counter = 0;
		if (!(*list = (t_etrimino *)malloc(sizeof(t_etrimino))))
			return ;
		create_object(list, buff, counter);
		return ;
	}
	counter = 1;
	temp = *list;
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
		++counter;
	}
	if (!(temp->next = (t_etrimino *)malloc(sizeof(t_etrimino))))
		return ;
	temp = temp->next;
	create_object(&temp, buff, counter);
}

int			validate(char *buff)
{
	int counter;

	g_i = -1;
	counter = 0;
	g_ccount = 0;
	while (++g_i < 20)
	{
		if ((g_i + 1) % 5 == 0 && buff[g_i] == '\n')
			continue;
		if (buff[g_i] != '.' && buff[g_i] != '#')
			return (0);
		if (buff[g_i] == '#')
		{
			if (++g_ccount && ((g_i + 1) < 20 && buff[g_i + 1] == '#'))
				counter++;
			if ((g_i - 1) >= 0 && buff[g_i - 1] == '#')
				counter++;
			if ((g_i + 5) < 20 && buff[g_i + 5] == '#')
				counter++;
			if ((g_i - 5) >= 0 && buff[g_i - 5] == '#')
				counter++;
		}
	}
	return ((counter == 6 || counter == 8) && g_ccount == 4 ? 1 : 0);
}

t_etrimino	*read_tetriminos(int fd, int *square_size, int *error)
{
	t_etrimino	*list;
	char		buff[BUFF_SIZE + 1];
	int			file;

	list = NULL;
	while ((file = read(fd, buff, BUFF_SIZE)))
	{
		++*square_size;
		buff[BUFF_SIZE] = '\0';
		if (file != BUFF_SIZE || validate(&buff[0]) == 0)
		{
			*error = 1;
			return (NULL);
		}
		create_list(&list, buff);
		if (read(fd, buff, 1) == 0)
			return (list);
	}
	*error = 1;
	return (list);
}
