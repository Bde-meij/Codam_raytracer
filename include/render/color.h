#ifndef COLOR_H
# define COLOR_H

# include <vec3.h>
# include <stdint.h>

void		color_add(t_vec3 *light, const t_vec3 *color, const t_vec3 *add);
void		color_scale(t_vec3 *light, double scale);

uint32_t	color_to_uint32(t_vec3 *color);

#endif