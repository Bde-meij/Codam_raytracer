/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:18:34 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:18:34 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "point_light.h"
# include "ray.h"
# include "hit_record.h"

t_vec3	calculate_specular_light(const t_point_light *light, \
	const t_ray *light_ray, const t_hit_record *hit_record);
t_vec3	calculate_light_factor(const t_point_light *light, \
	const t_ray *light_ray, const t_hit_record *hit_record);

#endif