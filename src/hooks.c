/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:53 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:53 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "render/color.h"

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>

void	display_imagedata(t_hook_data *hook_data)
{
	uint32_t	x;
	uint32_t	y;
	t_vec3		color;

	y = 0;
	while (y < hook_data->height)
	{
		x = 0;
		while (x < hook_data->width)
		{
			color = vec3_scalar(&hook_data->image_data[y * \
			hook_data->width + x], 1.0 / \
			(hook_data->current_ray_per_pixel + 1));
			mlx_put_pixel(hook_data->image, x, y, color_to_uint32(&color));
			x++;
		}
		y++;
	}
}

void	putpixel_f(uint32_t x, uint32_t y, t_vec3 color, void *data)
{
	t_hook_data	*hook_data;

	hook_data = data;
	hook_data->image_data[y * hook_data->width + x] = \
	vec3_add(&hook_data->image_data[y * hook_data->width + x], &color);
}

void	renderhook(void *data)
{
	t_hook_data	*hook_data;

	hook_data = data;
	if (hook_data->resize || hook_data->image_data == NULL)
	{
		mlx_resize_image(hook_data->image, hook_data->width, hook_data->height);
		hook_data->image->enabled = false;
		free(hook_data->image_data);
		hook_data->image_data = ft_calloc(hook_data->width * \
		hook_data->height, sizeof(t_vec3));
		hook_data->resize = false;
		hook_data->current_ray_per_pixel = 0;
		return ;
	}
	if (hook_data->current_ray_per_pixel >= hook_data->max_ray_per_pixel \
		|| hook_data->width == 0 || hook_data->height == 0)
		return ;
	render(hook_data->render_params, (t_pixelcallback){.function = putpixel_f, \
	.data = hook_data}, hook_data->width, hook_data->height);
	display_imagedata(hook_data);
	hook_data->image->enabled = true;
	hook_data->current_ray_per_pixel++;
	printf("current_ray_per_pixel: %d\n", hook_data->current_ray_per_pixel);
}

void	resizehook(int width, int height, void *data)
{
	t_hook_data	*hook_data;

	hook_data = data;
	hook_data->width = width;
	hook_data->height = height;
	hook_data->resize = true;
}

void	escapehook(mlx_key_data_t key, void *data)
{
	t_hook_data	*hook_data;

	hook_data = data;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(hook_data->mlx);
}
