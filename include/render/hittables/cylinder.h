#ifndef CYLINDER_H
# define CYLINDER_H

# include "render/hittables/hittable.h"
# include "render/ray.h"

typedef struct s_cylinder
{
	double	radius;
	double	height;
}	t_cylinder;

t_hittable_data	cylinder_new(const double radius, const double height);
bool			cylinder_hit(const t_hittable *hittable, const t_ray *ray, \
					t_hit_record *hit_record);
void			cylinder_destroy(void *data);

#endif
