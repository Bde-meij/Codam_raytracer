#include "hooks.h"
#include <stdlib.h>
#include <stdio.h>

int putpixel_f(uint32_t x, uint32_t y, t_vec3 color, void *data)
{
	t_hook_data *hook_data = data;

	hook_data->image_data[y * hook_data->width + x] = vec3_add(&hook_data->image_data[y * hook_data->width + x], &color);
	return (0);
}


void	renderhook(void *data)
{
	t_hook_data *hook_data = data;

	if (hook_data->resize || hook_data->image_data == NULL)
	{
		mlx_resize_image(hook_data->image, hook_data->width, hook_data->height);
		hook_data->image->enabled = false;
		free(hook_data->image_data);
		hook_data->image_data = malloc(sizeof(t_vec3) * hook_data->width * hook_data->height);
		for (uint32_t y = 0; y < hook_data->height; y++)
		{
			for (uint32_t x = 0; x < hook_data->width; x++)
			{
				hook_data->image_data[y * hook_data->width + x] = vec3_new(0, 0, 0);
			}
		}
		hook_data->resize = false;
		hook_data->current_ray_per_pixel = 0;
		return ;
	}

	if (hook_data->current_ray_per_pixel >= hook_data->max_ray_per_pixel)
		return ;

	render(hook_data->render_params, putpixel_f, hook_data, hook_data->width, hook_data->height);
	for (uint32_t y = 0; y < hook_data->height; y++)
	{
		for (uint32_t x = 0; x < hook_data->width; x++)
		{
			t_vec3 color = vec3_scalar(&hook_data->image_data[y * hook_data->width + x], 1.0 / (hook_data->current_ray_per_pixel + 1));
			mlx_put_pixel(hook_data->image, x, y, color_to_uint32(&color));
		}
	}
	hook_data->image->enabled = true;
	hook_data->current_ray_per_pixel++;
	printf("current_ray_per_pixel: %d\n", hook_data->current_ray_per_pixel);
}

void	resizehook(int width, int height, void *data)
{
	t_hook_data *hook_data = data;
	hook_data->width = width;
	hook_data->height = height;
	hook_data->resize = true;
}

void	escapehook(mlx_key_data_t key, void *data)
{
	t_hook_data *hook_data = data;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(hook_data->mlx);
}
