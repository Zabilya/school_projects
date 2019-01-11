/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:51:43 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/04 15:51:44 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

t_mylist	*new_list(int fd)
{
	t_mylist *list;

	if (!(list = (t_mylist *)malloc(sizeof(t_mylist))))
		return (NULL);
	list->content = (char *)malloc(1);
	list->content[0] = '\0';
	list->file_desc = fd;
	list->next = NULL;
	return (list);
}

int			write_char(char **line, char **content)
{
	char	*to_content;
	int		start;
	int		end;
	char	*all_content;
	char	*all_line;

	start = 0;
	end = 0;
	all_content = *content;
	while (all_content[start] != '\n')
		start++;
	while (all_content[start + end + 1])
		end++;
	if (start == 0)
		*line = (char *)malloc(1);
	else
		*line = ft_strsub(*content, 0, start);
	all_line = *line;
	all_line[start] = '\0';
	to_content = ft_strsub(*content, start + 1, end);
	to_content[end] = '\0';
	free(*content);
	*content = to_content;
	return (1);
}

int			case_of_eof(char **line, char **content)
{
	char	*temp;

	*line = (char *)malloc(ft_strlen(*content));
	*line = ft_strcpy(*line, *content);
	free(*content);
	*content = (char *)malloc(1);
	temp = *content;
	temp[0] = '\0';
	return (1);
}

int			read_buff(char **line, char **content, int fd)
{
	int		file;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	while ((file = read(fd, buff, BUFF_SIZE)))
	{
		buff[file] = '\0';
		if (!(temp = ft_strjoin(*content, &(buff[0]))))
			return (-1);
		free(*content);
		*content = temp;
		if (ft_strchr(*content, '\n'))
			return (write_char(line, content));
	}
	if (ft_strlen(*content) == 0)
		return (0);
	else
		return (case_of_eof(line, content));
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static	t_mylist	*list;
	t_mylist			*temp;
	char				*buf[1];

	if (!line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (list == NULL)
		list = new_list(fd);
	temp = list;
	while (!(temp->file_desc == fd))
	{
		if (temp->next == NULL)
			temp->next = new_list(fd);
		temp = temp->next;
	}
	if (ft_strchr(temp->content, '\n'))
		return (write_char(line, &(temp->content)));
	else
		return (read_buff(line, &(temp->content), fd));
}
