/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emayert <emayert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:29:07 by cschuste          #+#    #+#             */
/*   Updated: 2019/02/22 20:32:18 by emayert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

int		main(int ac, char **av)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	if (ac == 2)
	{
		init_mlx(e);
		create_objects(e, av[1]);
		render(e);
		mlx_hook(e->win, 17, 0L, clean_n_close, e);
		mlx_hook(e->win, 2, 0, key_hook, e);
		mlx_loop(e->mlx);
	}
	ft_putendl(MSG_USAGE);
	clean_n_close(e);
}
