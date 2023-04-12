/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lenght.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:44 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:44 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

#include <math.h>

VEC3_TYPE	vec3_lenght(const t_vec3 *lhs)
{
	return (sqrt(vec3_lenght_squared(lhs)));
}

VEC3_TYPE	vec3_lenght_c(const t_vec3 lhs)
{
	return (vec3_lenght(&lhs));
}
