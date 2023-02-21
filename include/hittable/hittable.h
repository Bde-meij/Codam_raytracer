#ifndef HITTABLE_H
# define HITTABLE_H

#include <stdint.h>
#include <vec3.h>
#include "ray.h"
#include <stdbool.h>

typedef enum e_hittable_object_type
{
	SPHERE
}	t_hittable_type;

typedef struct e_hittable_data
{
	void			*data;
	t_hittable_type	type;
}	t_hittable_data;

typedef struct s_hittable
{
	t_vec3	center;
	t_vec3	orientation;
	uint8_t	color[3];

	t_hittable_data	data;
}	t_hittable;

typedef struct s_hit_record
{
	const t_hittable	*object;
	bool	hit;
	t_vec3	point;
	double	distance;
}	t_hit_record;

t_hittable	*hittable_new(const t_vec3 center, const t_vec3 orientation, const uint8_t color[3], t_hittable_data data);

t_hit_record hittable_hit(const t_hittable *hittable, const t_ray *ray, const double t_min, const double t_max);


void hittable_destroy(t_hittable *hittable);

#endif
