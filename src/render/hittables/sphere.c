#include "render/hittables/sphere.h"
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#include <stdio.h>

t_hittable_data	sphere_new(const double radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return ((t_hittable_data){.data = NULL, .type = ERROR});
	sphere->radius = radius;
	return ((t_hittable_data){.data = sphere, .type = SPHERE});
}

void	sphere_destroy(void *data)
{
	free(data);
}

void	initialize_sphere_abc(const t_hittable *hittable, const t_ray *ray, \
t_abc_vars *abc_vars)
{
	abc_vars->relative_raypos = vec3_subtract(&ray->origin, &hittable->center);
	abc_vars->a = vec3_lenght_squared(&ray->direction);
	abc_vars->b = vec3_dot(&abc_vars->relative_raypos, &ray->direction);
	abc_vars->c = vec3_lenght_squared(&abc_vars->relative_raypos) - \
	pow(((t_sphere *)hittable->data.data)->radius, 2);
	abc_vars->discriminant = pow(abc_vars->b, 2) - abc_vars->a * abc_vars->c;
}

void	sphere_hit_recorder(const t_hittable *hittable, const t_ray *ray, \
t_hit_record *hit_record, double root)
{
	t_vec3	normal;

	hit_record->distance = root;
	hit_record->point = ray_at(ray, root);
	hit_record->object = hittable;
	normal = vec3_divide_c(vec3_subtract(&hit_record->point, \
	&hittable->center), ((t_sphere *)hittable->data.data)->radius);
	hit_record_set_normal(hit_record, ray, &normal);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
}

bool	sphere_hit(const t_hittable *hittable, const t_ray *ray, \
	t_hit_record *hit_record)
{
	t_abc_vars	abc_vars;
	double		root;

	initialize_sphere_abc(hittable, ray, &abc_vars);
	if (abc_vars.discriminant < 0)
		return (false);
	root = (-abc_vars.b - sqrt(abc_vars.discriminant)) / abc_vars.a;
	if (root < ray->min_distance || ray->max_distance < root)
	{
		root = (-abc_vars.b + sqrt(abc_vars.discriminant)) / abc_vars.a;
		if (root < ray->min_distance || ray->max_distance < root)
			return (false);
	}
	if (hit_record == NULL)
		return (true);
	sphere_hit_recorder(hittable, ray, hit_record, root);
	return (true);
}
