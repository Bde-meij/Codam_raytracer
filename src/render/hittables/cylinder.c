#include "render/hittables/cylinder.h"

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#include <stdio.h>

t_hittable_data cylinder_new(const double radius, const double height)
{
	t_cylinder	*cylinder;
	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return ((t_hittable_data){.data = NULL, .type = ERROR});
	cylinder->radius = radius;
	cylinder->height = height;
	return ((t_hittable_data){.data = cylinder, .type = CYLINDER});
}

void cylinder_destroy(void *data)
{
	free(data);
}

bool cylinder_hit_caps(const t_hittable *hittable, const t_ray *ray, t_hit_record *hit_record)
{
	t_vec3 center_bot = vec3_add_c(hittable->center, vec3_scalar(&hittable->orientation, ((t_cylinder *)hittable->data.data)->height / 2));
	t_vec3 center_top = vec3_subtract_c(hittable->center, vec3_scalar(&hittable->orientation, ((t_cylinder *)hittable->data.data)->height / 2));

	double t_bot = vec3_dot_c(vec3_subtract(&center_bot, &ray->origin), hittable->orientation) / vec3_dot(&ray->direction, &hittable->orientation);
	double t_top = vec3_dot_c(vec3_subtract(&center_top, &ray->origin), hittable->orientation) / vec3_dot(&ray->direction, &hittable->orientation);

	double t;
	t_vec3 center;
	if (t_bot < t_top)
	{
		center = center_bot;
		t = t_bot;
	}
	else
	{
		center = center_top;
		t = t_top;	
	}

	if (t < ray->min_distance || t > ray->max_distance)
		return (false);

	t_vec3 point = ray_at(ray, t);

	t_vec3 CP = vec3_subtract(&center, &point);

	if (vec3_lenght(&CP) > ((t_cylinder *)hittable->data.data)->radius)
		return (false);

	if (hit_record == NULL)
		return (true);

	hit_record->distance = t;
	hit_record->point = point;
	hit_record->object = hittable;

	hit_record_set_normal(hit_record, ray, &hittable->orientation);
	return (true);
}

bool cylinder_hit(const t_hittable *hittable, const t_ray *ray, t_hit_record *hit_record)
{
	
	if (cylinder_hit_caps(hittable, ray, hit_record))
		return (true);

	t_vec3	oc = vec3_subtract(&ray->origin, &hittable->center);
	double 	a = vec3_dot(&ray->direction, &ray->direction) - vec3_dot(&ray->direction, &hittable->orientation) * vec3_dot(&ray->direction, &hittable->orientation);
	double 	b = 2 * (vec3_dot(&ray->direction, &oc) - (vec3_dot(&ray->direction, &hittable->orientation) * vec3_dot(&oc, &hittable->orientation)));
	double 	c = vec3_dot(&oc, &oc) - (vec3_dot(&oc, &hittable->orientation) * vec3_dot(&oc, &hittable->orientation)) - (((t_cylinder *)hittable->data.data)->radius * ((t_cylinder *)hittable->data.data)->radius);

	double discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (false);
	
	double sqrtd = sqrt(discriminant);
	double root = (-b - sqrtd) / (a * 2);
	if (root < ray->min_distance || ray->max_distance < root)
	{
		root = (-b + sqrtd) / (a * 2);
		if (root < ray->min_distance || ray->max_distance < root)
			return (false);
	}

	t_vec3 point = ray_at(ray, root);

	t_vec3 CP = vec3_subtract(&point, &hittable->center);

	double CP_len = vec3_lenght(&CP);
	double CQ_len = sqrt((CP_len * CP_len) - (((t_cylinder *)hittable->data.data)->radius * ((t_cylinder *)hittable->data.data)->radius));

	if (CQ_len > ((t_cylinder *)hittable->data.data)->height / 2)
		return (false);

	if (hit_record == NULL)
		return (true);

	t_vec3 CQ = vec3_scalar(&hittable->orientation, CQ_len);
	t_vec3 Q1 = vec3_add(&hittable->center, &CQ);
	t_vec3 Q2 = vec3_subtract(&hittable->center, &CQ);
	t_vec3 QP1 = vec3_subtract(&point, &Q1);
	t_vec3 QP2 = vec3_subtract(&point, &Q2);
	double QP1_len = vec3_lenght_squared(&QP1);
	double QP2_len = vec3_lenght_squared(&QP2);

	t_vec3 QP;
	if (QP1_len < QP2_len)
		QP = QP1;
	else
		QP = QP2;

	hit_record->distance = root;
	hit_record->point = point;
	hit_record->object = hittable;
	
	t_vec3 normal = vec3_normalize(&QP);
	hit_record_set_normal(hit_record, ray, &normal);
	return (true);
}
