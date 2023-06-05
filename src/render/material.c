/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:39 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:39 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/material.h"

t_material	material_new(const t_vec3 color)
{
	t_material	material;

	material.color = vec3_divide(&color, 255);
	material.specular = 1;
	return (material);
}
