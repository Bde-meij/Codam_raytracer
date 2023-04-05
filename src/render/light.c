#include "render/light.h"
#include <math.h>


t_vec3 calculate_specular_light(const t_point_light *light, const t_ray *light_ray, const t_hit_record *hit_record)
{
	t_vec3 specular_light = light->color;

	t_vec3 reflected = vec3_reflect(&light_ray->direction, &hit_record->normal);
	double specular_factor = vec3_dot(&reflected, &hit_record->ray_direction);

	if (specular_factor > 0)
		color_scale(&specular_light, pow(specular_factor, hit_record->object->specular));
	else
		color_scale(&specular_light, 0);
	return (specular_light);
}

t_vec3 calculate_light_factor(const t_point_light *light, const t_ray *light_ray, const t_hit_record *hit_record)
{
	t_vec3 light_factor = light->color;
	double light_dot_normal = vec3_dot(&hit_record->normal, &light_ray->direction);
	if (light_dot_normal < 0)
		light_dot_normal = 0;
	color_scale(&light_factor, light_dot_normal);
	return (light_factor);
}