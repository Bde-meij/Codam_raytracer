#include "render/hittables/circle.h"

#include <stdlib.h>

t_hittable_data	circle_new(const double radius)
{
	t_circle	*circle;

	circle = malloc(sizeof(t_circle));
	if (circle == NULL)
		return ((t_hittable_data){NULL, ERROR});
	circle->radius = radius;
	return ((t_hittable_data){circle, CIRCLE});
}

void	circle_destroy(void *data)
{
	free(data);
}

bool	circle_hit(const t_hittable *hittable, const t_ray *ray, \
	t_hit_record *hit_record)
{
	const double	t = vec3_dot_c(vec3_subtract(&hittable->center, \
		&ray->origin), hittable->orientation) / \
		vec3_dot(&ray->direction, &hittable->orientation);
	t_vec3			point;

	if (t < ray->min_distance || t > ray->max_distance)
		return (false);
	point = ray_at(ray, t);
	if (vec3_lenght_c(vec3_subtract(&hittable->center, &point)) > \
		((t_circle *)hittable->data.data)->radius)
		return (false);
	if (hit_record == NULL)
		return (true);
	hit_record->distance = t;
	hit_record->point = point;
	hit_record->object = hittable;
	hit_record_set_normal(hit_record, ray, &hittable->orientation);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
	return (true);
}
