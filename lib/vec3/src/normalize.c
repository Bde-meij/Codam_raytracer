/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:51 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:51 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_normalize(const t_vec3 *vec)
{
	const VEC3_TYPE	length = vec3_length(vec);

	if (length == 0)
		return (vec3_new(0, 0, 0));
	return (vec3_divide(vec, length));
}

t_vec3	vec3_normalize_c(const t_vec3 vec)
{
	return (vec3_normalize(&vec));
}
