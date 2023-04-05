#ifndef HITTABLE_H
# define HITTABLE_H

#include <stdint.h>
#include <vec3.h>
#include <stdbool.h>

typedef struct s_hittable t_hittable;
typedef struct s_hittable_data t_hittable_data;
typedef enum e_hittable_object_type t_hittable_type;

#include "render/ray.h"
#include "render/hit_record.h"

enum e_hittable_object_type
{
	ERROR = -1,
	SPHERE,
	CYLINDER,
	PLANE
};

struct s_hittable_data
{
	void			*data;
	t_hittable_type	type;
};

struct s_hittable
{
	t_vec3	center;
	t_vec3	orientation;
	t_vec3	color;
	double  specular;

	t_hittable_data	data;
};


t_hittable	*hittable_new(const t_vec3 center, const t_vec3 orientation, const t_vec3 color, double specular, t_hittable_data data);

bool hittable_hit(const t_hittable *hittable, const t_ray *ray, t_hit_record *hit_record);

void hittable_destroy(t_hittable *hittable);

#endif
