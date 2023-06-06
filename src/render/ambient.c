/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ambient.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:27 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:27 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/ambient.h"

#include <stdlib.h>

t_ambient	ambient_new(const t_vec3 color, double brightness)
{
	t_ambient	ret;

	ret.color = vec3_scalar_c(vec3_divide(&color, 255), brightness);
	return (ret);
}

const t_vec3	*ambient_color(const t_ambient *ambient)
{
	return (&ambient->color);
}

void	ambient_destroy(t_ambient *ambient)
{
	free(ambient);
}
