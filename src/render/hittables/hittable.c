/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hittable.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:17:13 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/05 16:17:13 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render/hittable.h"
#include "render/ray.h"

#include <libft.h>
#include <stdbool.h>
#include <stdarg.h>

t_hittable	hittable_new(const t_hittable_type type, t_material material, ...)
{
	t_hittable		hittable;
	va_list			args;

	hittable.type = type;
	hittable.material = material;
	va_start(args, material);
	if (type == SPHERE)
		hittable.data.sphere = sphere_new(va_arg(args, t_vec3), \
			va_arg(args, double));
	else if (type == CYLINDER)
		hittable.data.cylinder = cylinder_new(va_arg(args, t_vec3), \
			va_arg(args, t_vec3), va_arg(args, double), va_arg(args, double));
	else if (type == PLANE)
		hittable.data.plane = plane_new(va_arg(args, t_vec3), \
			va_arg(args, t_vec3));
	else if (type == CIRCLE)
		hittable.data.circle = circle_new(va_arg(args, t_vec3), \
			va_arg(args, t_vec3), va_arg(args, double));
	else if (type == PIPE)
		hittable.data.pipe = pipe_new(va_arg(args, t_vec3), \
			va_arg(args, t_vec3), va_arg(args, double), va_arg(args, double));
	return (hittable);
}

bool	hittable_hit(const t_hittable *hittable, const t_ray *ray, \
	t_hit_record *hit_record)
{
	bool	hit_anything;

	hit_anything = false;
	if (hittable->type == SPHERE)
		hit_anything = sphere_hit(&hittable->data.sphere, ray, hit_record);
	else if (hittable->type == CYLINDER)
		hit_anything = cylinder_hit(&hittable->data.cylinder, ray, hit_record);
	else if (hittable->type == PLANE)
		hit_anything = plane_hit(&hittable->data.plane, ray, hit_record);
	else if (hittable->type == CIRCLE)
		hit_anything = circle_hit(&hittable->data.circle, ray, hit_record);
	else if (hittable->type == PIPE)
		hit_anything = pipe_hit(&hittable->data.pipe, ray, hit_record);
	else
		ft_putstr_fd("Error: hittable_hit(): invalid type\n", 1);
	if (hit_anything && hit_record != NULL)
		hit_record->material = hittable->material;
	return (hit_anything);
}
