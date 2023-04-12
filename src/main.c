#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include "render/hittables/hittable.h"
#include "render/hittables/sphere.h"
#include "render/hittables/cylinder.h"
#include "render/hittables/plane.h"

#include "hooks.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define MAX_RAY_PER_PIXEL 100

t_render_params	*sample_config(void)
{
	t_render_params *render_params = render_params_new();

	render_params->camera = camera_new(vec3_new(0, 0, 0), vec3_new(0, 0, 1), 70);
	render_params->light =  point_light_new(vec3_new(-1, 0, 1), vec3_new(1, 1, 1), 0.8);
	render_params->ambient_light = vec3_scalar_c(vec3_new(1, 1, 1), 0.2);
	render_params->hittables = hittable_array_new(2); //TODO: protect null

	// hittable_array_append(&render_params->hittables, hittable_new(vec3_new(0, 0, 5), (t_vec3){}, vec3_new(0, 0, 1), 10, sphere_new(1)));
	hittable_array_append(&render_params->hittables, hittable_new(vec3_new(2, 0, 5), vec3_new(0, 1, 1), vec3_new(1, 0, 0), sphere_new(1)));
	hittable_array_append(&render_params->hittables, hittable_new(vec3_new(0, 0, 10), vec3_new(0, 0, 1), vec3_new(0, 1, 0), plane_new())); //TODO: protect null
	
	return (render_params);
}

int32_t	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;


	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	t_hook_data hook_data = {
		.mlx = mlx,
		.width = SCREEN_WIDTH,
		.height = SCREEN_HEIGHT,
		.render_params = sample_config(),
		.image = img,
		.image_data = NULL,
		.max_ray_per_pixel = MAX_RAY_PER_PIXEL
	};

	mlx_key_hook(mlx, escapehook, &hook_data);
	mlx_resize_hook(mlx, resizehook, &hook_data);
	mlx_loop_hook(mlx, renderhook, &hook_data);
	mlx_loop(mlx);
	render_params_destroy(hook_data.render_params);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}
