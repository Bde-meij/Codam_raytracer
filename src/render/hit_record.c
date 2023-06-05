/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hit_record.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:35 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:35 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hit_record.h"

void	hit_record_set_normal(t_hit_record *record, const t_ray *ray, \
	const t_vec3 *outward_normal)
{
	record->outward_normal = *outward_normal;
	if (vec3_dot(&record->outward_normal, &ray->direction) > 0)
		record->normal = vec3_reverse(&record->outward_normal);
	else
		record->normal = record->outward_normal;
}
