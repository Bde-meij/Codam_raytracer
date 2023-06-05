/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:25 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:25 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"
#include <math.h>
#include <stddef.h>

t_sphere	sphere_new(const t_vec3 center, const double radius)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.radius = radius;
	return (sphere);
}

void	initialize_sphere_abc(const t_sphere *sphere, const t_ray *ray, \
t_abc_vars *abc_vars)
{
	abc_vars->relative_raypos = vec3_subtract(&ray->origin, &sphere->center);
	abc_vars->a = vec3_length_squared(&ray->direction);
	abc_vars->b = vec3_dot(&abc_vars->relative_raypos, &ray->direction);
	abc_vars->c = vec3_length_squared(&abc_vars->relative_raypos) - \
	pow(sphere->radius, 2);
	abc_vars->discriminant = pow(abc_vars->b, 2) - abc_vars->a * abc_vars->c;
}

void	sphere_hit_recorder(const t_sphere *sphere, const t_ray *ray, \
t_hit_record *hit_record, double root)
{
	t_vec3	normal;

	hit_record->distance = root;
	hit_record->point = ray_at(ray, root);
	normal = vec3_divide_c(vec3_subtract(&hit_record->point, \
	&sphere->center), sphere->radius);
	hit_record_set_normal(hit_record, ray, &normal);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
}

bool	sphere_hit(const t_sphere *sphere, const t_ray *ray, \
	t_hit_record *hit_record)
{
	t_abc_vars	abc_vars;
	double		root;

	initialize_sphere_abc(sphere, ray, &abc_vars);
	if (abc_vars.discriminant < 0)
		return (false);
	root = (-abc_vars.b - sqrt(abc_vars.discriminant)) / abc_vars.a;
	if (root < ray->min_distance || ray->max_distance < root)
	{
		root = (-abc_vars.b + sqrt(abc_vars.discriminant)) / abc_vars.a;
		if (root < ray->min_distance || ray->max_distance < root)
			return (false);
	}
	if (hit_record == NULL)
		return (true);
	sphere_hit_recorder(sphere, ray, hit_record, root);
	return (true);
}
