#include "camera.h"
#include "render.h"
#include <math.h>
#include <libft.h>
 
# include <stdio.h>

t_camera *camera_new(const t_vec3 position, const t_vec3 direction, double aspect_ratio, int hfov)
{
	printf("aspect ratio: %f\n", aspect_ratio);
	const t_vec3	camera_up = vec3_new(0, 1, 0);
	const double viewport_width = 2.0 * tan(to_radians(hfov)/ 2);
	const double viewport_height = viewport_width / aspect_ratio;
	
	t_camera *ret = malloc(sizeof(t_camera));
	if (ret == NULL)
		return (NULL);
	t_vec3	w = vec3_normalize(&direction);
	printf("w: "); vec3_print(&w);
	t_vec3	u = vec3_normalize_c(vec3_cross(&camera_up, &w));
	printf("u: "); vec3_print(&u);
	t_vec3	v = vec3_cross(&u, &w);
	printf("v: "); vec3_print(&v);

	printf("viewport width: %f, viewport height: %f\n", viewport_width, viewport_height);
	
	ret->origin = position;
	ret->horizontal = vec3_scalar(&u, viewport_width);
	ret->vertical = vec3_scalar(&v, viewport_height);
	printf("origin: "); vec3_print(&ret->origin);
	printf("horizontal: "); vec3_print(&ret->horizontal);
	printf("vertical: "); vec3_print(&ret->vertical);

	t_vec3 half_horizontal = vec3_divide(&ret->horizontal, 2);
	t_vec3 half_vertical = vec3_divide(&ret->vertical, 2);
	printf("horizontal tmp: "); vec3_print(&half_horizontal);
	printf("vertical tmp: "); vec3_print(&half_vertical);

	ret->lower_left_corner = vec3_subtract_c(vec3_subtract_c(vec3_subtract_c(ret->origin, half_horizontal), half_vertical), w);
	printf("corner: "); vec3_print(&ret->lower_left_corner);
	return (ret);
}

t_ray camera_generate_ray(const t_camera *camera, double width_pct, double height_pct)
{
	t_vec3	direction;

	direction = camera->lower_left_corner;
	direction = vec3_add_c(direction, vec3_scalar(&camera->horizontal, width_pct));
	direction = vec3_add_c(direction, vec3_scalar(&camera->vertical, height_pct));

	direction = vec3_subtract(&direction, &camera->origin);

	return ((t_ray){.origin = camera->origin, .direction = direction});
}

void camera_destroy(t_camera *camera)
{
	free(camera);
}
