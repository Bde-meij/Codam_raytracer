#include "vec3.h"

#include <stdio.h>
#include <stdint.h>

void vec3_fill(t_vec3 *vec, const VEC3_TYPE val)
{
	uint_fast8_t	i;

	i = 0;
	while (i < 3)
	{
		vec->data[i] = val;
		i++;
	}
}

void 	vec3_print(const t_vec3 *vec)
{
	uint_fast8_t	i;

	i = 0;
	while (i < 3)
	{
		printf("%f ", vec->data[i]);
		i++;
	}
	printf("\n");
}

void 	vec3_print_c(const t_vec3 vec)
{
	vec3_print(&vec);
}
