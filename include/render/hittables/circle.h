#ifndef CIRCLE_H
# define CIRCLE_H

# include "hittable.h"
# include "render/ray.h"

typedef struct s_circle
{
	double	radius;
}	t_circle;

t_hittable_data	circle_new(double radius);
bool			circle_hit(const t_hittable *hittable, const t_ray *ray, \
						t_hit_record *hit_record);
void			circle_destroy(void *data);
#endif
