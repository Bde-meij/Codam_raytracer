#include "render/hittables/plane.h"
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

t_hittable_data	plane_new(void)
{
	return ((t_hittable_data){.data = NULL, .type = PLANE});
}

void	plane_destroy(void *data)
{
	(void)data;
}

bool	plane_hit(const t_hittable *hittable, const t_ray *ray, \
	t_hit_record *hit_record)
{
	double	t;

	t = vec3_dot_c(vec3_subtract(&hittable->center, \
	&ray->origin), hittable->orientation) / \
	vec3_dot(&ray->direction, &hittable->orientation);
	if (t < ray->min_distance || t > ray->max_distance)
		return (false);
	if (hit_record == NULL)
		return (true);
	hit_record->distance = t;
	hit_record->point = ray_at(ray, t);
	hit_record->object = hittable;
	hit_record_set_normal(hit_record, ray, &hittable->orientation);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
	return (true);
}
