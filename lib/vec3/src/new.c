/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:49 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:49 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_new(const VEC3_TYPE v1, const VEC3_TYPE v2, const VEC3_TYPE v3)
{
	return ((t_vec3){.data = {v1, v2, v3}});
}
