/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   circle.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:04 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:04 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"
#include <stddef.h>

t_circle	circle_new(const t_vec3 center, const t_vec3 orientation, \
	const double radius)
{
	t_circle	circle;

	circle.center = center;
	circle.orientation = vec3_normalize(&orientation);
	circle.radius = radius;
	return (circle);
}

bool	circle_hit(const t_circle *circle, const t_ray *ray, \
	t_hit_record *hit_record)
{
	const double	t = vec3_dot_c(vec3_subtract(&circle->center, \
		&ray->origin), circle->orientation) / \
		vec3_dot(&ray->direction, &circle->orientation);
	t_vec3			point;

	if (t < ray->min_distance || t > ray->max_distance)
		return (false);
	point = ray_at(ray, t);
	if (vec3_length_c(vec3_subtract(&circle->center, &point)) > \
		circle->radius)
		return (false);
	if (hit_record == NULL)
		return (true);
	hit_record->distance = t;
	hit_record->point = point;
	hit_record_set_normal(hit_record, ray, &circle->orientation);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
	return (true);
}
