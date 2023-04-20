#ifndef AMBIENT_H
# define AMBIENT_H

# include <vec3.h>
# include "ray.h"
# include "color.h"
# include "hittables/hittable.h"

typedef struct s_ambient
{
	t_vec3  color;
}   t_ambient;

t_ambient *ambient_new(const t_vec3 color, double brightness);
void    ambient_destroy(t_ambient *ambient);

const t_vec3 *ambient_color(const t_ambient *ambient);

#endif
