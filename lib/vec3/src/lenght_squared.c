#include "vec3.h"

#include <stdint.h>

VEC3_TYPE vec3_lenght_squared(const t_vec3 *lhs)
{
	return (vec3_dot(lhs, lhs));
}

VEC3_TYPE vec3_lenght_squared_c(const t_vec3 lhs)
{
	return (vec3_lenght_squared(&lhs));
}
