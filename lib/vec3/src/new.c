#include "vec3.h"

t_vec3	vec3_new(const VEC3_TYPE v1, const VEC3_TYPE v2, const VEC3_TYPE v3)
{
	t_vec3 ret;

	vec3_set(&ret, v1, v2, v3);
	return (ret);
}
