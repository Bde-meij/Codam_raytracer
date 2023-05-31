#ifndef MATERIAL_H
# define MATERIAL_H

# include <vec3.h>

typedef struct s_material
{
	t_vec3	color;
	double	specular;
}	t_material;

t_material			material_new(const t_vec3 color);

#endif
