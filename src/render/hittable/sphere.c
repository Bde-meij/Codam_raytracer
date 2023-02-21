#include "hittable/sphere.h"

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

t_hittable_data sphere_new(const double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return ((t_hittable_data){.data = NULL});
	sphere->radius = radius;
	return ((t_hittable_data){.data = sphere, .type = SPHERE});
}

void sphere_destroy(void *data)
{
	free(data);
}

t_hit_record sphere_hit(const t_hittable *hittable, const t_ray *ray, const double t_min, const double t_max)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec3_subtract(&ray->origin, &hittable->center);
	a = vec3_dot(&ray->direction, &ray->direction);
	half_b = vec3_dot(&oc, &ray->direction);
	c = vec3_dot(&oc, &oc) - ((t_sphere *)hittable->data.data)->radius * ((t_sphere *)hittable->data.data)->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return ((t_hit_record){.hit = false});
	
	double sqrtd = sqrt(discriminant);

	double root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return ((t_hit_record){.hit = false});
    }
	
	return ((t_hit_record){.hit = true, .distance = root, .point = ray_at(ray, root), .object = hittable});
}
