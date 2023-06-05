/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lenght_squared.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:42 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:42 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

#include <stdint.h>

VEC3_TYPE	vec3_length_squared(const t_vec3 *lhs)
{
	return (vec3_dot(lhs, lhs));
}

VEC3_TYPE	vec3_length_squared_c(const t_vec3 lhs)
{
	return (vec3_length_squared(&lhs));
}
