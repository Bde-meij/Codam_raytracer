#include "render/light.h"
#include "render/render.h"

#include <stdlib.h>

t_light *light_new(const t_vec3 origin, const t_vec3 color, double brightness)
{
	t_light *new;

	new = malloc(sizeof(t_light));
	if (new == NULL)
		return (NULL);
	new->origin = origin;
	new->color = vec3_scalar(&color, brightness);
	return (new);
}

void light_destroy(t_light *light)
{
	free(light);
}

t_ray light_generate_ray(const t_light *light, const t_hit_record *hit_record)
{
	const t_vec3 direction = vec3_subtract(&light->origin, &hit_record->point);

	const t_vec3 origin = vec3_add_c(hit_record->point, vec3_scalar(&hit_record->normal, 0.0001));

	return (ray_new(&origin, &direction, 0, vec3_lenght(&direction)));
}
