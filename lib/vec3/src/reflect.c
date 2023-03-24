#include "vec3.h"

t_vec3 vec3_reflect(const t_vec3 *v, const t_vec3 *n)
{
	return (vec3_subtract_c(*v, vec3_scalar_c(*n, 2 * vec3_dot(v, n))));
}

t_vec3 vec3_reflect_c(const t_vec3 v, const t_vec3 n)
{
	return (vec3_subtract_c(v, vec3_scalar_c(n, 2 * vec3_dot(&v, &n))));
}
