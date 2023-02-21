#ifndef RENDER_H
# define RENDER_H

#include "hittable/hittable.h"
#include "hittable/array.h"
#include <stdint.h>
#include "camera.h"

typedef int (*t_putpixel_f)(uint32_t x, uint32_t y, uint32_t color, void *data);

typedef struct s_render_params
{
	uint32_t	width;
	uint32_t	height;
	t_putpixel_f	putpixel_f;
	void			*putpixel_data;

	t_hittable_array *hittables;
	t_camera		*camera;

}	t_render_params;

t_render_params *render_params_new(void);
void render_params_destroy(t_render_params *render_params);

int	render(t_render_params *render_params);

double to_degrees(double radians);
double to_radians(double degrees);
uint32_t	rgb_to_rgba(const uint8_t	color[3]);

#endif
