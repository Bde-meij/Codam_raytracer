#include "render/render.h"
#include <stddef.h>
#include <stdlib.h>

t_render_params *render_params_new(void)
{
	t_render_params *render_params;

	render_params = malloc(sizeof(t_render_params));
	if (render_params == NULL)
		return (NULL);
	render_params->hittables = NULL;
	render_params->camera = NULL;
	render_params->light = NULL;
	return (render_params);
}

void render_params_destroy(t_render_params *render_params)
{
	if (render_params == NULL)
		return ;
	hittable_array_destroy(render_params->hittables);
	camera_destroy(render_params->camera);
	point_light_array_destroy(render_params->light);
	free(render_params);
}
