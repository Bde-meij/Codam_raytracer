#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "render/render.h"
#include "render/hittables/hittable.h"
#include "render/hittables/array.h"

#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"

t_vec3 calculate_specular_light(const t_light *light, const t_ray *light_ray, const t_ray *camera_ray, const t_hit_record *hit_record)
{
	t_vec3 specular_light = light->color;

	t_vec3 reflected = vec3_reflect(&light_ray->direction, &hit_record->normal);
	double specular_factor = vec3_dot(&reflected, &camera_ray->direction);

	if (specular_factor > 0)
		color_scale(&specular_light, pow(specular_factor, hit_record->object->specular));
	else
		color_scale(&specular_light, 0);
	return (specular_light);
}

t_vec3 calculate_light_factor(const t_light *light, const t_ray *light_ray, const t_hit_record *hit_record)
{
	t_vec3 light_factor = light->color;
	double light_dot_normal = vec3_dot(&hit_record->normal, &light_ray->direction);
	if (light_dot_normal < 0)
		light_dot_normal = 0;
	color_scale(&light_factor, light_dot_normal);
	return (light_factor);
}

t_vec3 ray_to_color(const t_ray *ray, const t_hittable_array *hittables, const t_light *light, const t_vec3 *ambient_light)
{
	t_hit_record hit_record;
	t_vec3 light_color = VEC3_ZERO;
	if (hittable_array_hit(hittables, ray, &hit_record))
	{
		const t_vec3 *obj_color = &hit_record.object->color;
		t_ray light_ray = light_generate_ray(light, &hit_record);
		if (!hittable_array_hit(hittables, &light_ray, NULL))
		{
			t_vec3 point_light = calculate_light_factor(light, &light_ray, &hit_record);
			color_add(&light_color, obj_color, &point_light);

			t_vec3 specular_light = calculate_specular_light(light, &light_ray, ray, &hit_record);
			color_add(&light_color, &light->color, &specular_light);
		}
		color_add(&light_color, obj_color, ambient_light);
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
