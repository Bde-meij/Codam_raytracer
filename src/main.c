/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:56 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:56 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>

#include "hooks.h"
#include <fcntl.h>
#include "parse.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define MAX_RAY_PER_PIXEL 100

void	init_hook_data(t_hook_data *hook_data, mlx_t *mlx, \
t_render_params *render_params, mlx_image_t *img)
{
	hook_data->mlx = mlx;
	hook_data->width = SCREEN_WIDTH;
	hook_data->height = SCREEN_HEIGHT;
	hook_data->render_params = render_params;
	hook_data->image = img;
	hook_data->image_data = NULL;
	hook_data->max_ray_per_pixel = MAX_RAY_PER_PIXEL;
}

int	run_program(t_render_params *render_params)
{
	t_hook_data		hook_data;
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, \
		render_params->program_name, true);
	if (!mlx)
		return (print_error(MLX_ER), 1);
	img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img)
		return (print_error(MLX_ER), 1);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (print_error(MLX_ER), 1);
	init_hook_data(&hook_data, mlx, render_params, img);
	mlx_key_hook(mlx, escapehook, &hook_data);
	mlx_resize_hook(mlx, resizehook, &hook_data);
	if (!mlx_loop_hook(mlx, renderhook, &hook_data))
		return (print_error(MLX_ER), 1);
	mlx_loop(mlx);
	free(hook_data.image_data);
	mlx_terminate(mlx);
	return (0);
}

int32_t	main(int ac, char **av)
{
	int				fd;
	t_render_params	*render_params;

	if (ac != 2)
		return (print_error(N_ARGS_ER), EXIT_FAILURE);
	if (check_file(av[1]))
		return (print_error(WRONGFILE), EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_error(WRONGFILE), EXIT_FAILURE);
	render_params = render_params_new();
	if (render_params == NULL)
		return (print_error(MALLOC_ER), EXIT_FAILURE);
	render_params->program_name = ft_basename(av[1]);
	if (render_params->program_name == NULL)
		return (print_error(MALLOC_ER), EXIT_FAILURE);
	if (check_file_args(fd, render_params))
		return (EXIT_FAILURE);
	if (run_program(render_params))
		return (EXIT_FAILURE);
	render_params_destroy(render_params);
	return (EXIT_SUCCESS);
}
