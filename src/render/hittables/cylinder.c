#include "render/hittable.h"

#include <math.h>
#include <stddef.h>

t_cylinder	cylinder_new(const t_vec3 center, const t_vec3 orientation, \
	const double radius, const double height)
{
	t_cylinder	cylinder;

	cylinder.center = center;
	cylinder.orientation = orientation;
	cylinder.radius = radius;
	cylinder.height = height;
	return (cylinder);
}

bool cylinder_hit_caps(const t_cylinder *cylinder, const t_ray *ray, t_hit_record *hit_record)
{
	t_vec3 center_bot = vec3_add_c(cylinder->center, vec3_scalar(&cylinder->orientation, cylinder->height / 2));
	t_vec3 center_top = vec3_subtract_c(cylinder->center, vec3_scalar(&cylinder->orientation, cylinder->height / 2));
	double t_bot = vec3_dot_c(vec3_subtract(&center_bot, &ray->origin), cylinder->orientation) / vec3_dot(&ray->direction, &cylinder->orientation);
	double t_top = vec3_dot_c(vec3_subtract(&center_top, &ray->origin), cylinder->orientation) / vec3_dot(&ray->direction, &cylinder->orientation);
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
	if (vec3_lenght(&CP) > cylinder->radius)
		return (false);
	if (hit_record == NULL)
		return (true);
	hit_record->distance = t;
	hit_record->point = point;
	hit_record_set_normal(hit_record, ray, &cylinder->orientation);
	return (true);
}

void	initialize_cylinder_abc(const t_cylinder *cylinder, const t_ray *ray, \
t_abc_vars *abc_vars)
{
	abc_vars->relative_raypos = vec3_subtract(&ray->origin, &cylinder->center);
	abc_vars->a = vec3_dot(&ray->direction, &ray->direction) - \
	vec3_dot(&ray->direction, &cylinder->orientation) * \
	vec3_dot(&ray->direction, &cylinder->orientation);
	abc_vars->b = 2 * (vec3_dot(&ray->direction, &abc_vars->relative_raypos) - \
	(vec3_dot(&ray->direction, &cylinder->orientation) * \
	vec3_dot(&abc_vars->relative_raypos, &cylinder->orientation)));
	abc_vars->c = vec3_dot(&abc_vars->relative_raypos, &abc_vars->relative_raypos) - \
	(vec3_dot(&abc_vars->relative_raypos, &cylinder->orientation) * vec3_dot(&abc_vars->relative_raypos, \
	&cylinder->orientation)) - \
	pow(cylinder->radius, 2);
}

void	cylinder_hit_recorder(const t_ray *ray, \
t_hit_record *hit_record, double root, t_vec3 point, t_vec3 QP)
{
	hit_record->distance = root;
	hit_record->point = point;
	t_vec3 normal = vec3_normalize(&QP);
	hit_record_set_normal(hit_record, ray, &normal);
	hit_record->ray_direction = ray->direction;
	hit_record->ray_origin = ray->origin;
}

bool cylinder_hit(const t_cylinder *cylinder, const t_ray *ray, \
t_hit_record *hit_record)
{
	t_abc_vars	abc_vars;
	double		root;

	if (cylinder_hit_caps(cylinder, ray, hit_record))
		return (true);
	initialize_cylinder_abc(cylinder, ray, &abc_vars);
	abc_vars.discriminant = pow(abc_vars.b, 2) - (4 * abc_vars.a * abc_vars.c);
	if (abc_vars.discriminant < 0)
		return (false);
	double sqrtd = sqrt(abc_vars.discriminant);
	root = (-abc_vars.b - sqrtd) / (abc_vars.a * 2);
	if (root < ray->min_distance || ray->max_distance < root)
	{
		root = (-abc_vars.b + sqrtd) / (abc_vars.a * 2);
		if (root < ray->min_distance || ray->max_distance < root)
			return (false);
	}
	//raakpunt
	t_vec3 point = ray_at(ray, root);
	//center tot raakpunt
	t_vec3 CP = vec3_subtract(&point, &cylinder->center);
	//lengte van die lijn
	double CP_len = vec3_lenght(&CP);
	//verschil hoogte center en raakpunt
	double CQ_len = sqrt((CP_len * CP_len) - (cylinder->radius * cylinder->radius));
	if (CQ_len > cylinder->height / 2)
		return (false);
	if (hit_record == NULL)
		return (true);

	// if 0≤(Lint−C)⋅h≤‖h‖
	// The intersection is on the cylinder surface.

	//vector van cq-len
	t_vec3 CQ = vec3_scalar(&cylinder->orientation, CQ_len);
	//midden van cylinder op hoogte raakpunt 1
	t_vec3 Q1 = vec3_add(&cylinder->center, &CQ);
	//midden van cylinder op hoogte raakpunt 2
	t_vec3 Q2 = vec3_subtract(&cylinder->center, &CQ);
	//midden naar raakpunt 1
	t_vec3 QP1 = vec3_subtract(&point, &Q1);
	//midden naar raakpunt 2
	t_vec3 QP2 = vec3_subtract(&point, &Q2);
	//lengte van midden naar raakpunt 1
	double QP1_len = vec3_lenght_squared(&QP1);
	//lengte van midden naar raakpunt 2
	double QP2_len = vec3_lenght_squared(&QP2);
	t_vec3 QP;
	if (QP1_len < QP2_len)
		QP = QP1;
	else
		QP = QP2;
	cylinder_hit_recorder(ray, hit_record, root, point, QP);
	return (true);
}
