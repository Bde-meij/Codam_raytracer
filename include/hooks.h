/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:18:45 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:18:45 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <MLX42/MLX42.h>
# include "render/render.h"

typedef struct s_hook_data
{
	mlx_t			*mlx;
	uint32_t		width;
	uint32_t		height;
	t_render_params	*render_params;
	mlx_image_t		*image;
	t_vec3			*image_data;
	uint32_t		current_ray_per_pixel;
	uint32_t		max_ray_per_pixel;
	bool			resize;
}	t_hook_data;

void	renderhook(void *data);
void	escapehook(mlx_key_data_t key, void *data);
void	resizehook(int width, int height, void *data);

#endif
