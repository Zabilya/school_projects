/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:22:23 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/15 14:22:24 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static	char	*read_commands(void)
{
	char	*arr;
	char	buff[20000];
	int		file;
	int		fd;
	int		i;

	fd = open("mx.cl", O_RDONLY);
	file = read(fd, buff, 10000);
	arr = (char *)malloc(sizeof(char) * file);
	i = 0;
	while (i < file)
	{
		arr[i] = buff[i];
		i++;
	}
	return (arr);
}

static	int		cont_create(t_cl *cl)
{
	cl->kernel = clCreateKernel(cl->program, "iterate", &cl->err);
	if (!cl->kernel || cl->err != CL_SUCCESS)
		return (-6);
	cl->output = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY,
		MAP_X * MAP_Y * 4, NULL, NULL);
	if (!cl->output)
		return (-7);
	return (0);
}

static	int		create_cl_param(t_cl *cl)
{
	char	*kernel_source;

	cl->err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &cl->device_id, NULL);
	if (cl->err != CL_SUCCESS)
		return (-1);
	cl->context = clCreateContext(0, 1, &cl->device_id, NULL, NULL, &cl->err);
	if (!cl->context)
		return (-2);
	cl->commands = clCreateCommandQueue(cl->context, cl->device_id, 0,
		&cl->err);
	if (!cl->commands)
		return (-3);
	kernel_source = read_commands();
	cl->program = clCreateProgramWithSource(cl->context, 1,
		(const char**)&kernel_source, NULL, &cl->err);
	if (!cl->program)
		return (-4);
	cl->err = clBuildProgram(cl->program, 0, NULL, NULL, NULL, NULL);
	if (cl->err != CL_SUCCESS)
		return (-5);
	return (cont_create(cl));
}

void			main_for_gpu(t_all *all)
{
	t_gpu	*gpu;
	int		err;

	gpu = (t_gpu *)malloc(sizeof(t_gpu));
	gpu->all = all;
	gpu->cl = (t_cl *)malloc(sizeof(t_cl));
	err = create_cl_param(gpu->cl);
	if (err != 0)
	{
		ft_putendl("Param for GPU created. Run program one more time!");
		exit(0);
	}
	draw_gpu_fractal(gpu);
	mlx_mouse_hook(all->ptr->win, gpu_zoom, gpu);
	if (all->frac == 2)
		mlx_hook(all->ptr->win, 6, 0, gpu_julia_param, gpu);
	mlx_key_hook(all->ptr->win, gpu_destroy, gpu);
	mlx_hook(all->ptr->win, 17, 0, close_it, all);
	mlx_loop(all->ptr->mlx);
}
