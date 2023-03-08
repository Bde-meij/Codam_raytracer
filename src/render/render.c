#include "render.h"
#include "hittable/hittable.h"
#include "hittable/array.h"
#include  <float.h>

double screenx_to_modelx(uint32_t x, uint32_t width)
{
	return ((double)x / (width - 1));
}

double screeny_to_modely(uint32_t y, uint32_t height)
{
	return (1.0 - ((double)y / (height - 1)));
}

int	render(t_render_params *render_params)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < render_params->width)
	{
		y = 0;
		while (y < render_params->height)
		{
			t_ray ray = camera_generate_ray(render_params->camera, screenx_to_modelx(x, render_params->width), screeny_to_modely(y, render_params->height));
			t_hit_record hit_record = hittable_array_hit(render_params->hittables, &ray, 0, DBL_MAX);
			if (hit_record.hit)
				render_params->putpixel_f(x, y, rgb_to_rgba(hit_record.object->color), render_params->putpixel_data);
			else
				render_params->putpixel_f(x, y, rgb_to_rgba((uint8_t []){0, 0, 0}), render_params->putpixel_data);
			y++;
		}
		x++;
	}
	return (0);
}
