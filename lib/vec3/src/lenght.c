#include "vec3.h"

#include <math.h>

VEC3_TYPE vec3_lenght(const t_vec3 *lhs)
{
	return (sqrt(vec3_lenght_squared(lhs)));
}

VEC3_TYPE vec3_lenght_c(const t_vec3 lhs)
{
	return (vec3_lenght(&lhs));
}
