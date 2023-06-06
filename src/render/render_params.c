/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_params.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:46 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:46 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include <stddef.h>
#include <stdlib.h>

t_render_params	*render_params_new(void)
{
	t_render_params	*render_params;

	render_params = malloc(sizeof(t_render_params));
	if (render_params == NULL)
		return (NULL);
	render_params->hittables = hittable_array_new(10);
	if (render_params->hittables == NULL)
	{
		free(render_params);
		return (NULL);
	}
	return (render_params);
}

void	render_params_destroy(t_render_params *render_params)
{
	if (render_params == NULL)
		return ;
	hittable_array_destroy(render_params->hittables);
	free(render_params);
}
