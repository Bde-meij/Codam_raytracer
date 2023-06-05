/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:37 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:37 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/light.h"
#include "render/color.h"
#include <math.h>

t_vec3	calculate_specular_light(const t_point_light *light, \
	const t_ray *light_ray, const t_hit_record *hit_record)
{
	t_vec3	specular_light;
	t_vec3	reflected;
	double	specular_factor;

	specular_light = light->color;
	reflected = vec3_reflect(&light_ray->direction, &hit_record->normal);
	specular_factor = vec3_dot(&reflected, &hit_record->ray_direction);
	if (specular_factor > 0)
		color_scale(&specular_light, pow(specular_factor, \
			hit_record->material.specular));
	else
		color_scale(&specular_light, 0);
	return (specular_light);
}

t_vec3	calculate_light_factor(const t_point_light *light, \
	const t_ray *light_ray, const t_hit_record *hit_record)
{
	double	light_dot_normal;
	t_vec3	light_factor;

	light_dot_normal = vec3_dot(&hit_record->normal, &light_ray->direction);
	light_factor = light->color;
	if (light_dot_normal < 0)
		light_dot_normal = 0;
	color_scale(&light_factor, light_dot_normal);
	return (light_factor);
}
