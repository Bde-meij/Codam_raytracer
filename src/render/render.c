#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "render/render.h"
#include "render/hittables/hittable.h"
#include "render/light.h"

#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"

t_vec3 ray_to_color(const t_ray *ray, const t_hittable_array *hittables, const t_point_light_array *light, const t_vec3 *ambient_light)
{
	(void)(ambient_light);
	t_hit_record hit_record;
	t_vec3 light_color = VEC3_ZERO;
	if (hittable_array_hit(hittables, ray, &hit_record))
	{
		// const t_vec3 *obj_color = &hit_record.object->color;
		light_color = point_light_array_get_color(light, &hit_record, hittables);
		// color_add(&light_color, obj_color, ambient_light);
	}
	return (light_color);
}

double jitter(uint32_t max)
{
	return (random_double() / (double)max);
}

int	render(t_render_params *render_params, t_putpixel_f putpixel_f, void *putpixel_data, uint32_t width, uint32_t height)
{
	uint32_t	x;
	uint32_t	y;

	if (width == 0 || height == 0)
		return (1);
	camera_prepare(render_params->camera, (double)width / (double)height);
	x = 0;
	printf(HIDE_CURSOR);

	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			t_vec3 color = VEC3_ZERO;

			t_ray ray = camera_generate_ray(render_params->camera, screenx_to_modelx(x, width) + jitter(width), screeny_to_modely(y, height) + jitter(height));
			color = ray_to_color(&ray, render_params->hittables, render_params->light, &render_params->ambient_light);
			putpixel_f(x, y, vec3_clamp(&color, 0, 1), putpixel_data);
			y++;
		}
		if ((height / 100) != 0 && x % (height / 100) == 0)
		{
			printf("\rrendering %d%%", (int)((double)(x * height + y) / (width * height) * 100));
			fflush(stdout);
		}
		x++;
	}
	printf("\rrendering done\n" SHOW_CURSOR);
	fflush(stdout);
	return (0);
}
