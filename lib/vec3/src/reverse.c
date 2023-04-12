/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:29:55 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:29:55 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

#include <stdint.h>

t_vec3	vec3_reverse(const t_vec3 *vec)
{
	return (vec3_scalar(vec, -1));
}

t_vec3	vec3_reverse_c(const t_vec3 vec)
{
	return (vec3_reverse(&vec));
}
