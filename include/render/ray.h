#ifndef RAY_H
#define RAY_H

#include <vec3.h>

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	double  min_distance;
	double  max_distance;
} t_ray;

t_ray ray_new(const t_vec3 *origin, const t_vec3 *direction, const double min_distance, const double max_distance);

t_vec3 ray_at(const t_ray *ray, double distance);

#endif
