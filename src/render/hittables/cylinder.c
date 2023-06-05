/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:16:41 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:16:41 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"

#include <math.h>
#include <stddef.h>
#include <stdint.h>

t_cylinder	cylinder_new(const t_vec3 center, const t_vec3 orientation, \
	const double radius, const double height)
{
	t_cylinder			cylinder;
	t_vec3				endcap_centers[2];
	const t_vec3		orientation_norm = vec3_normalize(&orientation);

	endcap_centers[0] = vec3_add_c(center, \
	vec3_scalar(&orientation_norm, height / 2));
	endcap_centers[1] = vec3_subtract_c(center, \
	vec3_scalar(&orientation_norm, height / 2));
	cylinder.pipe = pipe_new(center, orientation, radius, height);
	cylinder.endcaps[0] = circle_new(endcap_centers[0], orientation, radius);
	cylinder.endcaps[1] = circle_new(endcap_centers[1], orientation, radius);
	return (cylinder);
}

bool	cylinder_hit(const t_cylinder *cylinder, const t_ray *ray, \
t_hit_record *hit_record)
{
	uint8_t			i;
	bool			is_hit[3];
	t_hit_record	hit_records[3];

	is_hit[0] = pipe_hit(&cylinder->pipe, ray, &hit_records[0]);
	is_hit[1] = circle_hit(&cylinder->endcaps[0], ray, &hit_records[1]);
	is_hit[2] = circle_hit(&cylinder->endcaps[1], ray, &hit_records[2]);
	if (!is_hit[0] && !is_hit[1] && !is_hit[2])
		return (false);
	if (hit_record == NULL)
		return (true);
	hit_record->distance = ray->max_distance;
	i = 0;
	while (i < 3)
	{
		if (is_hit[i] && fabs(hit_records[i].distance) < \
			fabs(hit_record->distance))
			*hit_record = hit_records[i];
		i++;
	}
	return (true);
}
