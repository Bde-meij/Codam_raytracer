#ifndef LIGHT_H
# define LIGHT_H

# include "point_light.h"
# include "ray.h"
# include "hit_record.h"
# include <vec3.h>

t_vec3	calculate_specular_light(const t_point_light *light, \
	const t_ray *light_ray, const t_hit_record *hit_record);
t_vec3	calculate_light_factor(const t_point_light *light, \
	const t_ray *light_ray, const t_hit_record *hit_record);

#endif