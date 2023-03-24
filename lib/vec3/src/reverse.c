#include "vec3.h"

#include <stdint.h>

t_vec3 vec3_reverse(const t_vec3 *vec)
{
	return (vec3_subtract(&VEC3_ZERO, vec));
}

t_vec3 vec3_reverse_c(const t_vec3 vec)
{
	return (vec3_reverse(&vec));
}
