#include "vec3.h"

#include <stdint.h>

t_vec3	vec3_multiply(const t_vec3 *lhs, const t_vec3 *rhs)
{
	uint_fast8_t i;
	t_vec3 ret;

	i = 0;
	while (i < 3)
	{
		ret.data[i] = lhs->data[i] * rhs->data[i];
		i++;
	}
	return (ret);
}

t_vec3	vec3_multiply_c(const t_vec3 lhs, const t_vec3 rhs)
{
	return (vec3_multiply(&lhs, &rhs));
}
