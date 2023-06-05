/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ambient.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:04:53 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:04:53 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include <vec3.h>

typedef struct s_ambient
{
	t_vec3	color;
}	t_ambient;

t_ambient		*ambient_new(const t_vec3 color, double brightness);
void			ambient_destroy(t_ambient *ambient);

const t_vec3	*ambient_color(const t_ambient *ambient);

#endif
