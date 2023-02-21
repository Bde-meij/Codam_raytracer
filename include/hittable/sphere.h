#ifndef SPHERE_H
#define SPHERE_H

#include "hittable/hittable.h"
#include "ray.h"

typedef struct s_sphere
{
	double	radius;
}	t_sphere;

t_hittable_data	sphere_new(const double radius);
t_hit_record	sphere_hit(const t_hittable *hittable, const t_ray *ray, const double t_min, const double t_max);
void			sphere_destroy(void *data);

#endif
