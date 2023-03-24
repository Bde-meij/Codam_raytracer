#ifndef HOOK_H
#define HOOK_H

#include <MLX42/MLX42.h>
#include "render/render.h"

typedef struct s_hook_data
{
	mlx_t	*mlx;
	uint32_t width;
	uint32_t height;
	t_render_params *render_params;
	mlx_image_t *image;
	t_vec3	*image_data;
	uint32_t current_ray_per_pixel;
	uint32_t max_ray_per_pixel;
	bool	resize;
}	t_hook_data;

void	renderhook(void *data);
void	escapehook(mlx_key_data_t key, void *data);
void	resizehook(int width, int height, void *data);


#endif
