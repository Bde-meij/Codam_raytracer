#include "ray.h"
#include <libft.h>

t_ray ray_new(const t_vec3 *origin, const t_vec3 *direction)
{
	return ((t_ray){.origin = *origin, .direction = *direction});
}

t_vec3	ray_at(const t_ray *ray, double distance)
{
	return (vec3_add_c(ray->origin, vec3_scalar(&ray->direction, distance)));
}
