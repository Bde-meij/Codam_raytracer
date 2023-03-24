#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <stddef.h>

typedef struct s_hittable_array
{
	t_hittable	**hittables;
	size_t		size;
	size_t 		capacity;
}	t_hittable_array;

t_hittable_array *hittable_array_new(const size_t preallocate_size);

t_hittable_array *hittable_array_append(t_hittable_array **array, t_hittable *hittable);

void hittable_array_destroy(t_hittable_array *array);

bool hittable_array_hit(const t_hittable_array *array, const t_ray *ray, t_hit_record *hit_record);

#endif
