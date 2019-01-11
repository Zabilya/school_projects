/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:44:29 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/10 10:44:29 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 20

typedef struct		s_etr
{
	int				raw;
	int				column;
	char			**tetrimino;
	struct s_etr	*next;

}					t_etrimino;

int					validate (char *buff);
int					calc_square(int tetr_num);
int					fillit(t_etrimino *list, int *side, char ***map, int num);
char				**create_tetrimino(char *buff, int counter);
void				free_arr(char ***arr);
void				free_list(t_etrimino **list);
char				**trunc_arr(char **arr, int *raw, int *column);
char				**create_map(int square_side);
char				**copy_map(char **map, int square_side);
t_etrimino			*read_tetriminos(int fd, int *square_size, int *error);

#endif
