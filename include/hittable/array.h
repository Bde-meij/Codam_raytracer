#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <stddef.h>

typedef struct s_hittable_array
{
	t_hittable	**hittables;
	size_t		size;
}	t_hittable_array;

t_hittable_array *hittable_array_new(const size_t size);

void hittable_array_set(t_hittable_array *list, const size_t index, t_hittable *hittable);

void hittable_array_destroy(t_hittable_array *list);

t_hit_record hittable_array_hit(const t_hittable_array *list, const t_ray *ray, const double t_min, const double t_max);

#endif
