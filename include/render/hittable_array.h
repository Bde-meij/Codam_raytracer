/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hittable_array.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:18:30 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:18:30 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_ARRAY_H
# define HITTABLE_ARRAY_H

# include <stdbool.h>
# include <stddef.h>

# include "render/hittable.h"
# include "render/ray.h"
# include "render/hit_record.h"

typedef struct s_hittable_array
{
	t_hittable	*hittables;
	size_t		size;
	size_t		capacity;
}	t_hittable_array;

t_hittable_array	*hittable_array_new(const size_t preallocate_size);
t_hittable_array	*hittable_array_append(t_hittable_array **array, \
					const t_hittable hittable);
void				hittable_array_destroy(t_hittable_array *array);
bool				hittable_array_hit(const t_hittable_array *array, \
	const t_ray *ray, t_hit_record *hit_record);

#endif
