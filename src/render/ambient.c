#include "render/ambient.h"
#include "render/render.h"

#include <stdlib.h>

t_ambient *ambient_new(const t_vec3 color, double brightness)
{
	t_ambient *new;

	new = malloc(sizeof(t_ambient));
	if (new == NULL)
		return (NULL);
	new->color = vec3_scalar_c(vec3_divide(&color, 255), brightness);
	return (new);
}

const t_vec3 *ambient_color(const t_ambient *ambient)
{
	return (&ambient->color);
}

void ambient_destroy(t_ambient *ambient)
{
	free(ambient);
}
