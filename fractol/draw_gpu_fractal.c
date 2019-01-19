/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gpu_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:08:25 by cschuste          #+#    #+#             */
/*   Updated: 2019/01/16 17:08:25 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	set_cl_global(t_cl *cl)
{
	cl->global = MAP_X * MAP_Y;
}

static	void	throw_exception(char *arr)
{
	ft_putendl(arr);
	exit(0);
}

static int		set_kernel_args(t_gpu *gpu)
{
	int		err;
	t_all	*all;
	int		map_x;
	int		map_y;

	map_x = MAP_X;
	map_y = MAP_Y;
	all = gpu->all;
	err = clSetKernelArg(gpu->cl->kernel, 0, sizeof(cl_mem), &gpu->cl->output)\
	+ clSetKernelArg(gpu->cl->kernel, 1, sizeof(double), &all->center->x)\
	+ clSetKernelArg(gpu->cl->kernel, 2, sizeof(double), &all->center->y)\
	+ clSetKernelArg(gpu->cl->kernel, 3, sizeof(double), &all->bound)\
	+ clSetKernelArg(gpu->cl->kernel, 4, sizeof(double), &all->step)\
	+ clSetKernelArg(gpu->cl->kernel, 5, sizeof(int), &all->frac)\
	+ clSetKernelArg(gpu->cl->kernel, 6, sizeof(int), &map_x)\
	+ clSetKernelArg(gpu->cl->kernel, 7, sizeof(int), &map_y)\
	+ clSetKernelArg(gpu->cl->kernel, 8, sizeof(int), &all->max_iter)\
	+ clSetKernelArg(gpu->cl->kernel, 9, sizeof(int), &all->colour)\
	+ clSetKernelArg(gpu->cl->kernel, 10, sizeof(double), &all->jul_po->x)\
	+ clSetKernelArg(gpu->cl->kernel, 11, sizeof(double), &all->jul_po->y);
	if (err != CL_SUCCESS)
		return (-1);
	return (0);
}

void			draw_gpu_fractal(t_gpu *gpu)
{
	int		err;
	t_cl	*cl;

	cl = gpu->cl;
	if (set_kernel_args(gpu) != 0)
		throw_exception("error in set_args");
	err = clGetKernelWorkGroupInfo(cl->kernel, cl->device_id, \
	CL_KERNEL_WORK_GROUP_SIZE, sizeof(cl->local), &cl->local, NULL);
	if (err != CL_SUCCESS)
		throw_exception("error in get workgroupinfo");
	set_cl_global(cl);
	err = clEnqueueNDRangeKernel(cl->commands, cl->kernel, 1, NULL, \
	&cl->global, &cl->local, 0, NULL, NULL);
	if (err)
		throw_exception("failed to execute kernel");
	clFinish(cl->commands);
	err = clEnqueueReadBuffer(cl->commands, cl->output, CL_TRUE, 0, \
	MAP_X * MAP_Y * 4, gpu->all->img, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		throw_exception("failed to read output");
	mlx_put_image_to_window(gpu->all->ptr->mlx, gpu->all->ptr->win, \
	gpu->all->ptr->img, 0, 0);
}
