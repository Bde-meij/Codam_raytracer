/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipe_hit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:17 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:17 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"
#include <stddef.h>
#include <math.h>

void	initialize_pipe_abc(const t_pipe *pipe, const t_ray *ray, \
t_abc_vars *abc_vars)
{
	abc_vars->relative_raypos = vec3_subtract(&ray->origin, &pipe->center);
	abc_vars->a = vec3_dot(&ray->direction, &ray->direction) - \
	vec3_dot(&ray->direction, &pipe->orientation) * \
	vec3_dot(&ray->direction, &pipe->orientation);
	abc_vars->b = 2 * (vec3_dot(&ray->direction, &abc_vars->relative_raypos) - \
	(vec3_dot(&ray->direction, &pipe->orientation) * \
	vec3_dot(&abc_vars->relative_raypos, &pipe->orientation)));
	abc_vars->c = vec3_dot(&abc_vars->relative_raypos, \
	&abc_vars->relative_raypos) - (vec3_dot(&abc_vars->relative_raypos, \
	&pipe->orientation) * vec3_dot(&abc_vars->relative_raypos, \
	&pipe->orientation)) - \
	pow(pipe->radius, 2);
	abc_vars->discriminant = pow(abc_vars->b, 2) - (4 * \
	abc_vars->a * abc_vars->c);
}

t_vec3	pipe_surface_normal(const t_pipe *pipe, const t_vec3 *point)
{
	const t_vec3	cp = vec3_subtract(point, &pipe->center);
	const t_vec3	normal = vec3_subtract_c(cp, \
		vec3_scalar(&pipe->orientation, vec3_dot(&cp, &pipe->orientation)));

	return (vec3_divide(&normal, pipe->radius));
}

bool	pipe_width_hit(const t_pipe *pipe, const t_ray *ray, \
	double *distance)
{
	t_abc_vars	abc_vars;
	double		t[2];
	double		sqrtd;

	initialize_pipe_abc(pipe, ray, &abc_vars);
	if (abc_vars.discriminant < 0)
		return (false);
	sqrtd = sqrt(abc_vars.discriminant);
	t[0] = (-abc_vars.b - sqrtd) / (abc_vars.a * 2);
	t[1] = (-abc_vars.b + sqrtd) / (abc_vars.a * 2);
	if ((t[0] < ray->min_distance || t[0] > ray->max_distance) && \
		(t[1] < ray->min_distance || t[1] > ray->max_distance))
		return (false);
	if (fabs(t[0]) < fabs(t[1]))
	{
		distance[0] = t[0];
		distance[1] = t[1];
	}
	else
	{
		distance[0] = t[1];
		distance[1] = t[0];
	}
	return (true);
}

bool	pipe_height_hit( const t_pipe *pipe, const t_ray *ray, \
	const double distance)
{
	t_vec3	point;
	double	cp_len;
	double	cq_len;

	if (distance < ray->min_distance || distance > ray->max_distance)
		return (false);
	point = ray_at(ray, distance);
	cp_len = vec3_length_c(vec3_subtract_c(point, pipe->center));
	cq_len = sqrt((cp_len * cp_len) - (pipe->radius * pipe->radius));
	if (cq_len > (pipe->height / 2))
		return (false);
	return (true);
}

bool	pipe_hit(const t_pipe *pipe, const t_ray *ray, \
	t_hit_record *hit_record)
{
	t_vec3		normal;
	double		t[2];
	double		distance;

	if (!pipe_width_hit(pipe, ray, t))
		return (false);
	distance = t[0];
	if (!pipe_height_hit(pipe, ray, t[0]))
	{
		if (!pipe_height_hit(pipe, ray, t[1]))
			return (false);
		distance = t[1];
	}
	if (hit_record == NULL)
		return (true);
	hit_record->distance = distance;
	hit_record->point = ray_at(ray, distance);
	normal = pipe_surface_normal(pipe, &hit_record->point);
	hit_record_set_normal(hit_record, ray, &normal);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
	return (true);
}
