/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:41 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:41 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/point_light.h"
#include "render/light.h"
#include "render/color.h"

#include <stdlib.h>

t_point_light	*point_light_new(const t_vec3 origin, \
	const t_vec3 color, double brightness)
{
	t_point_light	*new;

	new = malloc(sizeof(t_point_light));
	if (new == NULL)
		return (NULL);
	new->origin = origin;
	new->color = vec3_scalar_c(vec3_divide_c(color, 255), brightness);
	return (new);
}

void	point_light_destroy(t_point_light *light)
{
	free(light);
}

t_ray	point_light_generate_ray(const t_point_light *light, \
	const t_hit_record *hit_record)
{
	const t_vec3	direction = vec3_subtract(&light->origin, \
		&hit_record->point);
	const t_vec3	origin = vec3_add_c(hit_record->point, \
		vec3_scalar(&hit_record->normal, 0.0001));

	return (ray_new(&origin, &direction, 0, vec3_length(&direction)));
}

t_vec3	point_light_get_color(const t_point_light *light, \
	const t_hit_record *hit_record, const t_hittable_array *hittables)
{
	const t_ray	ray = point_light_generate_ray(light, hit_record);
	t_vec3		light_color;
	t_vec3		point_light;
	t_vec3		specular_light;

	if (hittable_array_hit(hittables, &ray, NULL))
		return (vec3_new(0, 0, 0));
	light_color = vec3_new(0, 0, 0);
	point_light = calculate_light_factor(light, &ray, hit_record);
	color_add(&light_color, &hit_record->material.color, &point_light);
	specular_light = calculate_specular_light(light, &ray, hit_record);
	color_add(&light_color, &light->color, &specular_light);
	return (light_color);
}
