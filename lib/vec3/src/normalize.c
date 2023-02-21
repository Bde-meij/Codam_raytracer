#include "vec3.h"

t_vec3	vec3_normalize(const t_vec3 *vec)
{
	const VEC3_TYPE length = vec3_lenght(vec);

	if (length == 0)
		return (vec3_new(0, 0, 0));
	return (vec3_divide(vec, length));
}

t_vec3	vec3_normalize_c(const t_vec3 vec)
{
	return (vec3_normalize(&vec));
}
