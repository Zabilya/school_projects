/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:46:45 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/04 15:47:09 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct		s_mylist
{
	char			*content;
	int				file_desc;
	struct s_mylist	*next;
}					t_mylist;

int					get_next_line(const int fd, char **line);

#endif
