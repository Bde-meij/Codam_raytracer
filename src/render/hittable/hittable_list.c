#include "hittable/array.h"
#include <float.h>
#include <stdlib.h>
#include <libft.h>

t_hittable_array *hittable_array_new(const size_t size)
{
	t_hittable_array *list;

	list = malloc(sizeof(t_hittable_array));
	if (!list)
		return (NULL);
	list->size = size;
	list->hittables = ft_calloc(size, sizeof(t_hittable *));
	if (!list->hittables)
	{
		free(list);
		return (NULL);
	}
	return (list);
}

void hittable_array_destroy(t_hittable_array *list)
{
	size_t i;

	if (list == NULL)
		return ;	
	i = 0;
	while (i < list->size)
	{
		hittable_destroy(list->hittables[i]);
		i++;
	}
	free(list->hittables);
	free(list);
}

void hittable_array_set(t_hittable_array *list, const size_t index, t_hittable *hittable)
{
	if (index >= list->size)
		return ;
	list->hittables[index] = hittable;
}

t_hit_record hittable_array_hit(const t_hittable_array *list, const t_ray *ray, const double t_min, const double t_max)
{
	t_hit_record closest;
	t_hit_record temp_record;
	size_t i;

	i = 0;
	closest.hit = false;
	closest.distance = t_max;
	while (i < list->size)
	{
		temp_record = hittable_hit(list->hittables[i], ray, t_min, closest.distance);
		if (temp_record.hit && temp_record.distance < closest.distance)
			closest = temp_record;
		i++;
	}
	return (closest);
}
