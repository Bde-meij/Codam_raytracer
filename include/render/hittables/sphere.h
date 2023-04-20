#ifndef SPHERE_H
# define SPHERE_H

# include "render/hittables/hittable.h"
# include "render/ray.h"

typedef struct s_sphere
{
	double	radius;
}	t_sphere;

t_hittable_data	sphere_new(const double radius);
void			sphere_destroy(void *data);
bool			sphere_hit(const t_hittable *hittable, const t_ray *ray, \
				t_hit_record *hit_record);

#endif
