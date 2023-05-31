#include "render/material.h"

t_material	material_new(const t_vec3 color)
{
	t_material	material;

	material.color = vec3_divide(&color, 255);
	material.specular = 10;
	return (material);
}
