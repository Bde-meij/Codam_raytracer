/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:45:31 by bde-meij          #+#    #+#             */
/*   Updated: 2023/04/20 14:52:57 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <float.h>
#include <libft.h>

// ∗ identifier: sp
// ∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
// ∗ the sphere diameter: 12.6
// ∗ R,G,B colors in range [0-255]: 10, 0, 255

int	check_sphere(char **str, t_render_params *render_params)
{
	double	radius;
	t_vec3	origin;
	t_vec3	color;

	if (ft_dstrlen(str) != 4)
		return (print_error(INCOMPLETE), 1);
	if (check_value_range(str[1], -DBL_MAX, DBL_MAX, 3) || \
		check_value_range(str[2], -DBL_MAX, DBL_MAX, 1) || \
		check_value_range(str[3], 0.0, 255.0, 3))
		return (print_error(OUTOFRANGE), 1);
	radius = atof(str[2]) * 0.5;
	origin = convert_array_to_vector(str[1]);
	color = convert_array_to_vector(str[3]);
	protec(hittable_array_append(&render_params->hittables, \
	hittable_new(SPHERE, material_new(color), origin, radius)));
	return (0);
}

// ∗ identifier: pl
// ∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
// ∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 
//0.0,1.0,0.0
// ∗ R,G,B colors in range [0-255]: 0,0,225

int	check_plane(char **str, t_render_params *render_params)
{
	if (ft_dstrlen(str) != 4)
		return (print_error(INCOMPLETE), 1);
	if (check_value_range(str[1], -DBL_MAX, DBL_MAX, 3) || \
		check_value_range(str[2], -1.0, 1.0, 3) || \
		check_value_range(str[3], 0.0, 255.0, 3))
		return (print_error(OUTOFRANGE), 1);
	protec(hittable_array_append(&render_params->hittables, \
	hittable_new(PLANE, material_new(convert_array_to_vector(str[3])), \
		convert_array_to_vector(str[1]), convert_array_to_vector(str[2]))));
	return (0);
}

// ∗ identifier: cy
// ∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
// ∗ 3d normalized vector of axis of cylinder. In range [-1,1] for 
//each x,y,z axis:
// 0.0,0.0,1.0
// ∗ the cylinder diameter: 14.2
// ∗ the cylinder height: 21.42
// ∗ R,G,B colors in range [0,255]: 10, 0, 255

int	check_cylinder(char **str, t_render_params *render_params)
{
	double	radius;
	double	height;

	if (ft_dstrlen(str) != 6)
		return (print_error(INCOMPLETE), 1);
	if (check_value_range(str[1], -DBL_MAX, DBL_MAX, 3) || \
		check_value_range(str[2], -1.0, 1.0, 3) || \
		check_value_range(str[3], -DBL_MAX, DBL_MAX, 1) || \
		check_value_range(str[4], -DBL_MAX, DBL_MAX, 1) || \
		check_value_range(str[5], 0.0, 255.0, 3))
		return (print_error(OUTOFRANGE), 1);
	radius = ft_atof(str[3]) * 0.5;
	height = ft_atof(str[4]);
	protec(hittable_array_append(&render_params->hittables, \
	hittable_new(CYLINDER, material_new(convert_array_to_vector(str[5])), \
	convert_array_to_vector(str[1]), convert_array_to_vector(str[2]), \
		radius, height)));
	return (0);
}

int	check_cone(char **str, t_render_params *render_params)
{
	double	radius;
	double	height;

	if (ft_dstrlen(str) != 6)
		return (print_error(INCOMPLETE), 1);
	if (check_value_range(str[1], -DBL_MAX, DBL_MAX, 3) || \
		check_value_range(str[2], -1.0, 1.0, 3) || \
		check_value_range(str[3], -DBL_MAX, DBL_MAX, 1) || \
		check_value_range(str[4], -DBL_MAX, DBL_MAX, 1) || \
		check_value_range(str[5], 0.0, 255.0, 3))
		return (print_error(OUTOFRANGE), 1);
	radius = ft_atof(str[3]) * 0.5;
	height = ft_atof(str[4]);
	protec(hittable_array_append(&render_params->hittables, \
	hittable_new(CONE, material_new(convert_array_to_vector(str[5])), \
	convert_array_to_vector(str[1]), convert_array_to_vector(str[2]), \
		radius, height)));
	return (0);
}

// ∗ identifier: co
// ∗ x,y,z coordinates of the center of the cone: 50.0,0.0,20.6
// ∗ 3d normalized vector of axis of cone. In range [-1,1] for each x,y,z axis:
// 0.0,0.0,1.0
// ∗ the cone diameter: 14.2
// ∗ the cone height: 21.42
// ∗ R,G,B colors in range [0,255]: 10, 0, 255

/*
int	check_cone(char **str, t_render_params *render_params)
{
	double	radius;
	double	height;
	
	if (ft_dstrlen(str) != 6)
		return (print_error(INCOMPLETE), 1);
	if (check_value_range(str[2], -1, 1) || \
		check_value_range(str[5], 0, 255) || checkiftof(str[4]) || \
			(checkiftof(str[4])))
		return (print_error(OUTOFRANGE), 1);
	radius = ft_atof(str[3]) * 0.5;
	height = ft_atof(str[4]);
	protec(hittable_array_append(&render_params->hittables, \
	hittable_new(convert_array_to_vector(str[1]), \
	convert_array_to_vector(str[2]), \
	convert_array_to_vector(str[3]), 30, cone_new(radius, height))));
	return (0);
}
*/
