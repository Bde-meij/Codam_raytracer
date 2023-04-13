#include "render/camera.h"
#include "render/render.h"
#include <math.h>
#include <libft.h>
#include <float.h>

t_camera	*camera_new(const t_vec3 position, \
	const t_vec3 direction, double hfov)
{
	t_camera	*ret;

	ret = malloc(sizeof(t_camera));
	if (ret == NULL)
		return (NULL);
	camera_update(ret, position, direction, hfov);
	return (ret);
}

void	camera_update(t_camera *camera, const t_vec3 position, \
	const t_vec3 direction, double hfov)
{
	camera->position = position;
	camera->direction = direction;
	camera->hfov = hfov;
	if (vec3_eq_c(camera->direction, vec3_new(0, 1, 0)))
		camera->up = vec3_new(0, 0, -1);
	else if (vec3_eq_c(camera->direction, vec3_new(0, -1, 0)))
		camera->up = vec3_new(0, 0, 1);
	else
		camera->up = vec3_new(0, 1, 0);
}

void	camera_prepare(t_camera *camera, double aspect_ratio)
{
	const double	viewport_width = 2.0 * tan(to_radians(camera->hfov) / 2);
	const double	viewport_height = viewport_width / aspect_ratio;
	const t_vec3	w = vec3_normalize_c(vec3_reverse(&camera->direction));
	const t_vec3	u = vec3_normalize_c(vec3_cross(&w, &camera->up));
	const t_vec3	v = vec3_cross(&u, &w);

	camera->horizontal = vec3_scalar(&u, viewport_width);
	camera->vertical = vec3_scalar(&v, viewport_height);
	camera->lower_left_corner = vec3_subtract_c(vec3_subtract_c(\
		vec3_subtract_c(camera->position, vec3_divide(&camera->horizontal, 2)), \
		vec3_divide(&camera->vertical, 2)), w);
}

t_ray	camera_generate_ray(const t_camera *camera, \
	double width_pct, double height_pct)
{
	t_vec3	direction;

	direction = camera->lower_left_corner;
	direction = vec3_add_c(direction, \
		vec3_scalar(&camera->horizontal, width_pct));
	direction = vec3_add_c(direction, \
		vec3_scalar(&camera->vertical, height_pct));
	direction = vec3_subtract(&direction, &camera->position);
	return (ray_new(&camera->position, &direction, 0, DBL_MAX));
}

void	camera_destroy(t_camera *camera)
{
	free(camera);
}
