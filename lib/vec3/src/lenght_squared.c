#include "vec3.h"

#include <stdint.h>

VEC3_TYPE vec3_lenght_squared(const t_vec3 *lhs)
{
	uint_fast8_t i;
	VEC3_TYPE	ret;

	i = 0;
	ret = 0;
	while (i < 3)
	{
		ret += lhs->data[i] * lhs->data[i];
		i++;
	}
	return (ret);
}

VEC3_TYPE vec3_lenght_squared_c(const t_vec3 lhs)
{
	return (vec3_lenght_squared(&lhs));
}
