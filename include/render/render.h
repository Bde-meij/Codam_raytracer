/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:18:43 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:18:43 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "hittable_array.h"
# include "camera.h"
# include "point_light.h"
# include "ambient.h"
# include <vec3.h>

# include <stdint.h>

# define RENDER_SHADOW_BIAS 0.0001

typedef void	(*t_pixelcallback_f)(uint32_t x, uint32_t y, \
	t_vec3 color, void *data);

typedef struct s_render_params
{
	char				*program_name;
	t_hittable_array	*hittables;
	t_point_light		light;
	t_ambient			ambient;
	t_camera			camera;
}	t_render_params;

typedef struct s_pixelcallback
{
	t_pixelcallback_f	function;
	void				*data;
}	t_pixelcallback;

t_render_params	*render_params_new(void);
void			render_params_destroy(t_render_params *render_params);

int				render(t_render_params *render_params, \
	t_pixelcallback pixelcallback, uint32_t width, uint32_t height);

double			to_degrees(double radians);
double			to_radians(double degrees);
double			screenx_to_modelx(uint32_t x, uint32_t width);
double			screeny_to_modely(uint32_t y, uint32_t height);
double			random_double(void);

#endif
