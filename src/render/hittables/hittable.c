#include <render/hittables/hittable.h>
#include "render/hittables/sphere.h"
#include "render/hittables/cylinder.h"
#include "render/hittables/plane.h"
#include "render/ray.h"

#include <libft.h>
#include <float.h>
#include <stdbool.h>

typedef void (*t_hittable_destroy_f)(void *);
typedef bool (*t_hittable_hit_f)(const t_hittable *, const t_ray *, t_hit_record *);

static const t_hittable_destroy_f	g_hittable_destroy_f[] = {
	[SPHERE] = sphere_destroy,
	[CYLINDER] = cylinder_destroy,
	[PLANE] = plane_destroy
};

static const t_hittable_hit_f	g_hittable_hit_f[] = {
	[SPHERE] = sphere_hit,
	[CYLINDER] = cylinder_hit,
	[PLANE] = plane_hit
};

t_hittable	*hittable_new(const t_vec3 center, const t_vec3 orientation, const t_vec3 color, double specular, t_hittable_data data)
{
	t_hittable	*new;

	if (data.type == ERROR)
		return (NULL);
	new = malloc(sizeof(t_hittable));
	if (new == NULL)
		return (NULL);
	new->center = center;
	new->orientation = vec3_normalize(&orientation);
	new->color = color;
	new->data = data;
	new->specular = specular;
	return (new);
}

void hittable_destroy(t_hittable *hittable)
{
	if (hittable == NULL)
		return ;
	g_hittable_destroy_f[hittable->data.type](hittable->data.data);
	free(hittable);
}

bool hittable_hit(const t_hittable *hittable, const t_ray *ray, t_hit_record *hit_record)
{
	return (g_hittable_hit_f[hittable->data.type](hittable, ray, hit_record));
}
