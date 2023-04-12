/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cross.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:36 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:36 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

#include <stdint.h>

t_vec3	vec3_cross(const t_vec3 *lhs, const t_vec3 *rhs)
{
	t_vec3	ret;

	ret.data[0] = (lhs->data[1] * rhs->data[2]) - (lhs->data[2] * rhs->data[1]);
	ret.data[1] = (lhs->data[2] * rhs->data[0]) - (lhs->data[0] * rhs->data[2]);
	ret.data[2] = (lhs->data[0] * rhs->data[1]) - (lhs->data[1] * rhs->data[0]);
	return (ret);
}

t_vec3	vec3_cross_c(const t_vec3 lhs, const t_vec3 rhs)
{
	return (vec3_cross(&lhs, &rhs));
}
