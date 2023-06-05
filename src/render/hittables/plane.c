/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:22 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:22 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"
#include <stddef.h>

t_plane	plane_new(const t_vec3 center, const t_vec3 orientation)
{
	t_plane	plane;

	plane.center = center;
	plane.orientation = vec3_normalize(&orientation);
	return (plane);
}

bool	plane_hit(const t_plane *plane, const t_ray *ray, \
	t_hit_record *hit_record)
{
	double	t;

	t = vec3_dot_c(vec3_subtract(&plane->center, \
	&ray->origin), plane->orientation) / \
	vec3_dot(&ray->direction, &plane->orientation);
	if (t < ray->min_distance || t > ray->max_distance)
		return (false);
	if (hit_record == NULL)
		return (true);
	hit_record->distance = t;
	hit_record->point = ray_at(ray, t);
	hit_record_set_normal(hit_record, ray, &plane->orientation);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
	return (true);
}
