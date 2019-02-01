/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:23:36 by cschuste          #+#    #+#             */
/*   Updated: 2019/02/01 15:23:37 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include "mlx.h"
# include <OpenCL/opencl.h>

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef	struct		s_all
{
	t_vector		camera;
}					t_all;

#endif