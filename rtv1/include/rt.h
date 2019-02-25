/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <cschuste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:23:36 by cschuste          #+#    #+#             */
/*   Updated: 2019/02/22 21:22:28 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif
# include "../lib/libft/libft.h"
# include "../lib/libmlx/mlx.h"
# include "../lib/libvec/libvec.h"
# include "keys.h"
# include <pthread.h>
# include <fcntl.h>
# include <math.h>

# define MSG_USAGE	"usage: ./RTv1 \e[33mscene number\e[0m\nnumber from 0 to 4"
# define RAY_LENMAX		2147483647
# define RAY_LENMIN		0.001
# define WIN_H			512
# define WIN_W			512
# define CLR_BACKGROUND	0
# define T_PLANE		0
# define T_SPHERE		1
# define T_CYLINDER		2
# define T_CONE			3

typedef	struct		s_camera
{
	t_v		rot;
	t_v		pos;
	void	*ptr_vp;
	int		*view_port_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}					t_cam;

typedef	struct		s_light
{
	t_v		pos;
	double	intensity;
	char	*type;
}					t_light;

typedef struct		s_render
{
	t_v		start;
	t_v		dest;
	double	min;
	int		max;
}					t_ren;

typedef	struct		s_object
{
	t_v					pos;
	t_v					rot;
	unsigned	char	colour[3];
	double				radius;
	int					specular;
	int					type;
}					t_obj;

typedef struct		s_light_container
{
	t_v		p;
	t_v		n;
	t_v		v;
	t_v		l;
	t_v		r;
	int		temp;
}					t_lc;

typedef	struct		s_objects_container
{
	t_obj	**objarr;
	int		n_cylinders;
	int		n_planes;
	int		n_sphere;
	int		n_cones;
	int		n_obj;
}					t_oc;

typedef	struct		s_bullshit
{
	double				posx;
	double				posy;
	double				posz;
	double				rotx;
	double				roty;
	double				rotz;
	double				rad;
	unsigned	char	r;
	unsigned	char	g;
	unsigned	char	b;
	int					spec;
	int					type;

}					t_bs;

typedef	struct		s_environment
{
	t_light	**light;
	t_cam	*cam;
	t_ren	*ren_var;
	t_lc	*lit_var;
	t_oc	*objs;
	void	*mlx;
	void	*win;
	int		k;
	int		lnum;
}					t_env;

t_v					normal2plane(t_env	*e, int i);
t_v					normal2cone(t_env *e, t_v dest, double closest, int i);
t_v					normal2cyl(t_env *e, t_v dest, double closest, int i);
t_v					vec_rotate(t_v a, t_v vec);
t_v					vp_to_global(t_v vp_p);
double				close_intersection(t_env *e, t_ren *r_v, int *num_obj);
void				create_any_ob(t_env *e,
									unsigned char *arr, t_v pos, int spec);
void				light_abuse(int *i, double *intens);
void				ppx_on_img(int x, int y, int color, t_env *e);
void				cr_obj(t_bs bs, int i, t_env *e);
void				create_objects(t_env *e, char *av);
void				rayhit_obj(t_v dest, t_env *e);
void				key_handler(int key, t_env *e);
void				create_scene_0(t_env *e);
void				create_scene_1(t_env *e);
void				create_scene_2(t_env *e);
void				create_scene_3(t_env *e);
void				create_scene_4(t_env *e);
void				init_mlx(t_env *e);
void				init_env(t_env *e);
void				render(t_env *e);
int					light_on(t_env *e, t_v dest, double closest, int i);
int					trace_ray_cylinder(t_v dest, t_env *e);
int					trace_ray_sphere(t_v dest, t_env *e);
int					trace_ray_plane(t_v dest, t_env *e);
int					trace_ray_cone(t_v dest, t_env *e);
int					key_hook(int key, t_env *e);
int					clean_n_close(t_env *e);
int					intersect_cylinder(t_v start,
										t_v dest, t_obj *cyl, double *t);
int					intersect_sphere(t_v start,
										t_v dest, t_obj *sph, double *t);
int					intersect_cone(t_v start,
										t_v dest, t_obj *cone, double *t);
int					intersect_plane(t_v start,
										t_v dest, t_obj *plane, double *t);
#endif
