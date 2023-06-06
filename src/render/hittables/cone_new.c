/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:18:47 by bde-meij          #+#    #+#             */
/*   Updated: 2023/06/06 11:18:54 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"

t_cone	cone_new(const t_vec3 center, const t_vec3 orientation, \
	const double radius, const double height)
{
	t_cone	cone;

	cone.center = center;
	cone.orientation = vec3_normalize(&orientation);
	cone.radius = radius;
	cone.height = height;
	return (cone);
}
