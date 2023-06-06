/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compare.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:25 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:25 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

#include <stdint.h>
#include <float.h>

bool	vec3_eq(const t_vec3 *lhs, const t_vec3 *rhs)
{
	uint_fast8_t	i;

	i = 0;
	while (i < 3)
	{
		if (lhs->data[i] + DBL_EPSILON < rhs->data[i] || \
			lhs->data[i] - DBL_EPSILON > rhs->data[i])
			return (0);
		i++;
	}
	return (1);
}

bool	vec3_eq_c(const t_vec3 lhs, const t_vec3 rhs)
{
	return (vec3_eq(&lhs, &rhs));
}
