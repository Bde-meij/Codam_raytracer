#include "render/hittables/sphere.h"

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

t_hittable_data sphere_new(const double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return ((t_hittable_data){.data = NULL, .type = ERROR});
	sphere->radius = radius;
	return ((t_hittable_data){.data = sphere, .type = SPHERE});
}

void sphere_destroy(void *data)
{
	free(data);
}

bool sphere_hit(const t_hittable *hittable, const t_ray *ray, t_hit_record *hit_record)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec3_subtract(&ray->origin, &hittable->center);
	a = vec3_lenght_squared(&ray->direction);
	half_b = vec3_dot(&oc, &ray->direction);
	c = vec3_lenght_squared(&oc) - (((t_sphere *)hittable->data.data)->radius * ((t_sphere *)hittable->data.data)->radius);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (false);
	
	double sqrtd = sqrt(discriminant);

	double root = (-half_b - sqrtd) / a;

	if (root < ray->min_distance || ray->max_distance < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < ray->min_distance || ray->max_distance < root)
			return (false);
	}

	if (hit_record == NULL)
		return (true);

	hit_record->distance = root;
	hit_record->point = ray_at(ray, root);
	hit_record->object = hittable;
	hit_record->ray_origin = ray->origin;
	hit_record->ray_direction = ray->direction;
	
	const t_vec3 normal = vec3_divide_c(vec3_subtract(&hit_record->point, &hittable->center), ((t_sphere *)hittable->data.data)->radius);
	hit_record_set_normal(hit_record, ray, &normal);

	return (true);
}
