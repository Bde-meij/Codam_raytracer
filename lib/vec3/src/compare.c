#include "vec3.h"

bool vec3_eq(const t_vec3 *lhs, const t_vec3 *rhs)
{
	int i = 0;

	while (i < 3)
	{
		if (lhs->data[i] != rhs->data[i])
			return (0);
		i++;
	}
	return (1);
}

bool vec3_eq_c(const t_vec3 lhs, const t_vec3 rhs)
{
	return (vec3_eq(&lhs, &rhs));
}
