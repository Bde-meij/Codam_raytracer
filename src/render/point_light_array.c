#include "render/point_light.h"
#include <libft.h>
#include <stdio.h>

t_point_light_array *point_light_array_new(const size_t preallocate_size)
{
	t_point_light_array *array;

	array = malloc(sizeof(t_point_light_array));
	if (!array)
		return (NULL);
	array->size = 0;
	array->capacity = preallocate_size;
	array->lights = ft_calloc(preallocate_size, sizeof(t_point_light *));
	if (!array->lights)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

t_point_light_array *point_light_array_append(t_point_light_array **array, t_point_light *light)
{
	if ((*array)->size >= (*array)->capacity)
	{
		(*array)->lights = ft_reallocf((*array)->lights, (*array)->capacity * sizeof(t_point_light *), (*array)->capacity * 2 * sizeof(t_point_light *));
		if (!*array)
			return (NULL);
		(*array)->capacity *= 2;
	}
	(*array)->lights[(*array)->size] = light;
	(*array)->size++;
	return (*array);
}

void point_light_array_destroy(t_point_light_array *array)
{
	size_t i;

	if (array == NULL)
		return ;
	i = 0;
	while (i < array->size)
	{
		point_light_destroy(array->lights[i]);
		i++;
	}
	free(array->lights);
	free(array);
}

t_vec3 point_light_array_get_color(const t_point_light_array *array, const t_hit_record *hit_record, const t_hittable_array *hittables)
{
	t_vec3 color;
	size_t i;

	color = VEC3_ZERO;
	i = 0;
	while (i < array->size)
	{
		t_vec3 light_color = point_light_get_color(array->lights[i], hit_record, hittables);
		color = vec3_add(&color, &light_color);
		i++;
	}
	// vec3_divide(&color, array->size);
	return (color);
}