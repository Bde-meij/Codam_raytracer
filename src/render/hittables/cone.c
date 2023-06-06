/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:18:14 by bde-meij          #+#    #+#             */
/*   Updated: 2023/06/06 12:12:26 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"
#include <math.h>
#include <stddef.h>

void	initialize_cone_abc(const t_cone *cone, const t_ray *ray, \
t_abc_vars *abc_vars)
{
	double	m;

	m = pow(cone->radius, 2) / vec3_dot(&cone->orientation, &cone->orientation);
	abc_vars->relative_raypos = vec3_subtract(&ray->origin, &cone->center);
	abc_vars->a = vec3_dot(&ray->direction, &ray->direction) - \
	m * vec3_dot(&ray->direction, &cone->orientation) * \
	vec3_dot(&ray->direction, &cone->orientation) - \
	vec3_dot(&ray->direction, &cone->orientation) * \
	vec3_dot(&ray->direction, &cone->orientation);
	abc_vars->b = 2 * (vec3_dot(&ray->direction, &abc_vars->relative_raypos) - \
	m * (vec3_dot(&ray->direction, &cone->orientation) * \
	vec3_dot(&abc_vars->relative_raypos, &cone->orientation)) - \
	(vec3_dot(&ray->direction, &cone->orientation) * \
	vec3_dot(&abc_vars->relative_raypos, &cone->orientation)));
	abc_vars->c = vec3_dot(&abc_vars->relative_raypos, \
	&abc_vars->relative_raypos) - m * ((vec3_dot(&abc_vars->relative_raypos, \
	&cone->orientation) * vec3_dot(&abc_vars->relative_raypos, \
	&cone->orientation))) - (vec3_dot(&abc_vars->relative_raypos, \
	&cone->orientation) * vec3_dot(&abc_vars->relative_raypos, \
	&cone->orientation));
	abc_vars->discriminant = pow(abc_vars->b, 2) - (4 * \
	abc_vars->a * abc_vars->c);
}

t_vec3	cone_surface_normal(const t_cone *cone, const t_vec3 *point)
{
	const t_vec3	cp = vec3_subtract(point, &cone->center);
	const t_vec3	normal = vec3_subtract_c(cp, \
		vec3_scalar(&cone->orientation, vec3_dot(&cp, &cone->orientation)));

	return (vec3_divide(&normal, cone->radius));
}

bool	cone_width_hit(const t_cone *cone, const t_ray *ray, \
	double *distance)
{
	t_abc_vars	abc_vars;
	double		t[2];
	double		sqrtd;

	initialize_cone_abc(cone, ray, &abc_vars);
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

bool	cone_height_hit( const t_cone *cone, const t_ray *ray, \
	const double distance)
{
	t_vec3	point;
	double	cp_len;
	double	cq_len;

	if (distance < ray->min_distance || distance > ray->max_distance)
		return (false);
	point = ray_at(ray, distance);
	cp_len = vec3_length_c(vec3_subtract_c(point, cone->center));
	cq_len = sqrt((cp_len * cp_len) - (cone->radius * cone->radius));
	if (cq_len > (cone->height / 2))
		return (false);
	return (true);
}

bool	cone_hit(const t_cone *cone, const t_ray *ray, \
	t_hit_record *hit_record)
{
	t_vec3		normal;
	double		t[2];
	double		distance;

	if (!cone_width_hit(cone, ray, t))
		return (false);
	distance = t[0];
	if (!cone_height_hit(cone, ray, t[0]))
	{
		if (!cone_height_hit(cone, ray, t[1]))
			return (false);
		distance = t[1];
	}
	if (hit_record == NULL)
		return (true);
	hit_record->distance = distance;
	hit_record->point = ray_at(ray, distance);
	normal = cone_surface_normal(cone, &hit_record->point);
	hit_record_set_normal(hit_record, ray, &normal);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
	return (true);
}
