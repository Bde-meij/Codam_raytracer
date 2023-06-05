/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:33 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:33 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/color.h"

void	color_add(t_vec3 *light, const t_vec3 *color, const t_vec3 *add)
{
	*light = vec3_add_c(*light, vec3_multiply(color, add));
}

void	color_scale(t_vec3 *light, double scale)
{
	*light = vec3_scalar(light, scale);
}

static double	color_clamp(double n, double min, double max)
{
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}

uint32_t	color_to_uint32(t_vec3 *color)
{
	const uint8_t	r = color_clamp(color->data[0], 0, 1) * 255;
	const uint8_t	g = color_clamp(color->data[1], 0, 1) * 255;
	const uint8_t	b = color_clamp(color->data[2], 0, 1) * 255;

	return (r << 24 | g << 16 | b << 8 | 0xFF);
}
