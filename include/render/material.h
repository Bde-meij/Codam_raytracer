/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:18:36 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:18:36 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include <vec3.h>

typedef struct s_material
{
	t_vec3	color;
	double	specular;
}	t_material;

t_material			material_new(const t_vec3 color);

#endif
