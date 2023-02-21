#include "vec3.h"

#include <stdint.h>

VEC3_TYPE vec3_dot(const t_vec3 *lhs, const t_vec3 *rhs)
{
	uint_fast8_t i;
	VEC3_TYPE ret;

	i = 0;
	ret = 0;
	while (i < 3)
	{
		ret += lhs->data[i] * rhs->data[i];
		i++;
	}
	return (ret);
}

VEC3_TYPE	vec3_dot_c(const t_vec3 lhs, const t_vec3 rhs)
{
	return (vec3_dot(&lhs, &rhs));
}
