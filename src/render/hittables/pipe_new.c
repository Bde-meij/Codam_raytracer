/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipe_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:20 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:20 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"

t_pipe	pipe_new(const t_vec3 center, const t_vec3 orientation, \
	const double radius, const double height)
{
	t_pipe	pipe;

	pipe.center = center;
	pipe.orientation = vec3_normalize(&orientation);
	pipe.radius = radius;
	pipe.height = height;
	return (pipe);
}
