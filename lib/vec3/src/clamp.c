/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clamp.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:32 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:32 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

#include <stdint.h>

static VEC3_TYPE	vec3_clamp_values(VEC3_TYPE n, VEC3_TYPE min, VEC3_TYPE max)
{
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}

t_vec3	vec3_clamp(const t_vec3 *v, const VEC3_TYPE min, const VEC3_TYPE max)
{
	t_vec3			ret;
	uint_fast8_t	i;

	i = 0;
	while (i < 3)
	{
		ret.data[i] = vec3_clamp_values(v->data[i], min, max);
		i++;
	}
	return (ret);
}

t_vec3	vec3_clamp_c(const t_vec3 v, const VEC3_TYPE min, const VEC3_TYPE max)
{
	return (vec3_clamp(&v, min, max));
}
