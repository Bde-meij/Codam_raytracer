/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filmset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:45:20 by bde-meij          #+#    #+#             */
/*   Updated: 2023/04/20 14:52:44 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <float.h>
#include <libft.h>

// ∗ identifier: A
// ∗ ambient lighting ratio in range [0.0,1.0]: 0.2
// ∗ R,G,B colors in range [0-255]: 255, 255, 255

int	check_ambient(char **str, t_render_params *render_params)
{
	if (ft_dstrlen(str) != 3)
		return (print_error(INCOMPLETE), 1);
	if (check_value_range(str[1], 0.0, 1.0, 1) || \
		check_value_range(str[2], 0.0, 255.0, 3))
		return (print_error(OUTOFRANGE), 1);
	render_params->ambient = \
	protec(ambient_new(convert_array_to_vector(str[2]), \
	ft_atof(str[1])));
	return (0);
}

// ∗ identifier: C
// ∗ x,y,z coordinates of the view point: -50.0,0,20
// ∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
// 0.0,0.0,1.0
// ∗ FOV : Horizontal field of view in degrees in range [0,180]: 70

int	check_camera(char **str, t_render_params *render_params)
{
	if (ft_dstrlen(str) != 4)
		return (print_error(INCOMPLETE), 1);
	if (check_value_range(str[1], -DBL_MAX, DBL_MAX, 3) || \
		check_value_range(str[2], -1.0, 1.0, 3) || \
		check_value_range(str[3], 0.0, 180.0, 1))
		return (print_error(OUTOFRANGE), 1);
	render_params->camera = \
	protec(camera_new(convert_array_to_vector(str[1]), \
	convert_array_to_vector(str[2]), ft_atof(str[3])));
	return (0);
}

// ∗ identifier: L
// ∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
// ∗ the light brightness ratio in range [0.0,1.0]: 0.6
// ∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255

int	check_light(char **str, t_render_params *render_params)
{
	if (ft_dstrlen(str) != 4 && ft_dstrlen(str) != 3)
		return (print_error(INCOMPLETE), 1);
	if (check_value_range(str[1], -DBL_MAX, DBL_MAX, 3) || \
		check_value_range(str[2], 0.0, 1.0, 1))
		return (print_error(OUTOFRANGE), 1);
	if (ft_dstrlen(str) == 4)
	{
		if (check_value_range(str[3], 0.0, 255.0, 3))
			return (print_error(OUTOFRANGE), 1);
		render_params->light = \
		protec(point_light_new(convert_array_to_vector(str[1]), \
		convert_array_to_vector(str[3]), ft_atof(str[2])));
	}
	else
		render_params->light = \
		protec(point_light_new(convert_array_to_vector(str[1]), \
		vec3_new(255, 255, 255), ft_atof(str[2])));
	return (0);
}
