#include <hittable/hittable.h>
#include <libft.h>
#include "ray.h"
#include "hittable/sphere.h"
#include <float.h>

typedef void (*t_hittable_destroy_f)(void *);
typedef t_hit_record (*t_hittable_hit_f)(const t_hittable *, const t_ray *, double, double);

static const t_hittable_destroy_f	g_hittable_destroy_f[] = {
	[SPHERE] = sphere_destroy
};

static const t_hittable_hit_f	g_hittable_hit_f[] = {
	[SPHERE] = sphere_hit
};

t_hittable	*hittable_new(const t_vec3 center, const t_vec3 orientation, const uint8_t color[3], t_hittable_data data)
{
	t_hittable	*new;

	if (data.data == NULL)
		return (NULL);
	new = malloc(sizeof(t_hittable));
	if (new == NULL)
		return (NULL);
	new->center = center;
	new->orientation = orientation;
	ft_memcpy(new->color, color, 3);
	new->data = data;
	return (new);
}

void hittable_destroy(t_hittable *hittable)
{
	if (hittable == NULL)
		return ;
	g_hittable_destroy_f[hittable->data.type](hittable->data.data);
	free(hittable);
}

t_hit_record hittable_hit(const t_hittable *hittable, const t_ray *ray, const double t_min, const double t_max)
{
	return (g_hittable_hit_f[hittable->data.type](hittable, ray, t_min, t_max));
}
