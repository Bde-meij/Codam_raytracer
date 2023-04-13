#include <stdlib.h>
#include <math.h>

#include "render/render.h"
#include "render/hittables/hittable.h"
#include "render/light.h"

t_vec3	ray_to_color(const t_ray *ray, const t_hittable_array *hittables, \
		const t_point_light *light, const t_vec3 *ambient_light)
{
	t_hit_record	hit_record;
	t_vec3			light_color;

	light_color = vec3_new(0, 0, 0);
	if (hittable_array_hit(hittables, ray, &hit_record))
	{
		light_color = point_light_get_color(light, &hit_record, hittables);
		color_add(&light_color, &hit_record.object->color, \
			ambient_light);
	}
	return (light_color);
}

double	jitter(uint32_t max)
{
	return (random_double() / (double)max);
}

t_vec3	trace_pixel(t_render_params *render_params, double pct_x, double pct_y)
{
	t_ray			ray;
	t_vec3			color;

	ray = camera_generate_ray(render_params->camera, pct_x, pct_y);
	color = ray_to_color(&ray, render_params->hittables, \
		render_params->light, &render_params->ambient_light);
	color = vec3_clamp(&color, 0, 1);
	return (color);
}

int	render(t_render_params *render_params, \
			t_pixelcallback pixelcallback, uint32_t w, uint32_t h)
{
	uint32_t	x;
	uint32_t	y;
	t_vec3		color;

	if (w == 0 || h == 0)
		return (1);

	camera_prepare(render_params->camera, (double)w / (double)h);
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			color = trace_pixel(render_params, screenx_to_modelx(x, w) + \
				jitter(w), screeny_to_modely(y, h) + jitter(h));
			pixelcallback.function(x, y, color, pixelcallback.data);
			y++;
		}
		x++;
	}
	return (0);
}
