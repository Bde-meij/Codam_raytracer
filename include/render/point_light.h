#ifndef POINT_LIGHT_H
# define POINT_LIGHT_H

# include <vec3.h>
# include "ray.h"
# include "hittable_array.h"

typedef struct s_point_light
{
	t_vec3	origin;
	t_vec3	color;
}	t_point_light;

t_point_light	*point_light_new(const t_vec3 origin, const t_vec3 color, \
	double brightness);
void			point_light_destroy(t_point_light *light);
t_ray			point_light_generate_ray(const t_point_light *light, \
	const t_hit_record *hit_record);
t_vec3			point_light_get_color(const t_point_light *light, \
	const t_hit_record *hit_record, const t_hittable_array *hittables);

#endif
