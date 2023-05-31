#ifndef HITTABLE_H
# define HITTABLE_H

# include <vec3.h>
# include <stdbool.h>
# include <stdarg.h>

# include  "render/material.h"
# include "render/ray.h"
# include "render/hit_record.h"


typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;

typedef struct s_circle
{
	t_vec3	center;
	t_vec3	orientation;
	double	radius;
}	t_circle;

typedef struct s_plane
{
	t_vec3	center;
	t_vec3	orientation;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	orientation;
	double	radius;
	double	height;
}	t_cylinder;

typedef enum e_hittable_type
{
	ERROR = -1,
	SPHERE,
	CYLINDER,
	PLANE,
	CIRCLE,
}	t_hittable_type;

typedef union u_hittable_data
{
	t_sphere		sphere;
	t_cylinder		cylinder;
	t_plane			plane;
	t_circle		circle;
}	t_hittable_data;

typedef struct s_hittable
{
	t_hittable_type		type;
	t_material			material;
	t_hittable_data		data;
}	t_hittable;

t_hittable			hittable_new(const t_hittable_type type, \
						t_material material, ...);
bool				hittable_hit(const t_hittable *hittable, const t_ray *ray, \
						t_hit_record *hit_record);

t_sphere			sphere_new(const t_vec3 center, const double radius);
bool				sphere_hit(const t_sphere *data, const t_ray *ray, \
						t_hit_record *hit_record);

t_cylinder			cylinder_new(const t_vec3 center, const t_vec3 orientation, \
						double radius, double height);
bool				cylinder_hit(const t_cylinder *data, const t_ray *ray, \
						t_hit_record *hit_record);

t_plane				plane_new(const t_vec3 center, const t_vec3 orientation);
bool				plane_hit(const t_plane *data, const t_ray *ray, \
						t_hit_record *hit_record);

t_circle			circle_new(const t_vec3 center, const t_vec3 orientation, \
						const double radius);
bool				circle_hit(const t_circle *data, const t_ray *ray, \
						t_hit_record *hit_record);

typedef struct s_abc_variables
{
	t_vec3	relative_raypos;
	double	a;
	double	b;
	double	c;
	double	discriminant;
}	t_abc_vars;

#endif