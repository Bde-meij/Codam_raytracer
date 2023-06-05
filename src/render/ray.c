/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:43 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:43 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/ray.h"

t_ray	ray_new(const t_vec3 *origin, const t_vec3 *direction, \
	const double min_distance, const double max_distance)
{
	return ((t_ray){.origin = *origin, .direction = vec3_normalize(direction), \
		.min_distance = min_distance, .max_distance = max_distance});
}

t_vec3	ray_at(const t_ray *ray, double distance)
{
	return (vec3_add_c(ray->origin, vec3_scalar(&ray->direction, distance)));
}
