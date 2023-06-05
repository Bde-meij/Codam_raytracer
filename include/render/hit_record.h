/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hit_record.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:18:28 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:18:28 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H

# include <vec3.h>
# include "render/material.h"
# include "render/ray.h"

typedef struct s_hit_record
{
	t_material			material;
	t_vec3				point;
	double				distance;
	t_vec3				normal;
	t_vec3				outward_normal;

	t_vec3				ray_direction;
	t_vec3				ray_origin;
}	t_hit_record;

void	hit_record_set_normal(t_hit_record *record, const t_ray *ray, \
	const t_vec3 *outward_normal);

#endif
