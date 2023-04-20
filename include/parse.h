#ifndef PARSE_H
# define PARSE_H

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <libft.h>
# include <stdio.h>
# include "render/hittables/sphere.h"
# include "render/ambient.h"
# include "render/hittables/plane.h"
# include "render/hittables/cylinder.h"
# include "render/render.h"

typedef enum e_parse_errors
{
	N_ARGS_ER,
	WRONGFILE,
	OUTOFRANGE,
	OBJECT_ER,
	INCOMPLETE,
	MALLOC_ER,
	NULL_ARG
}	t_parse_errors;

typedef struct s_jump_table
{
	char	*id;
	int		(*check_function)(char **, t_render_params *);
}	t_jump_table;

// error_handling
void	print_error(t_parse_errors error_code);
void	*protec(void *ptr);
int		check_file_args(int fd, t_render_params *render_params);
int		check_value_range(char *str, double min, double max, int expected_len);
int		check_file(char *file_name);
int		checkiftof(char *str);

// check_filmset
int		check_ambient(char **str, t_render_params *render_params);
int		check_camera(char **str, t_render_params *render_params);
int		check_light(char **str, t_render_params *render_params);

// check_objects
int		check_cylinder(char **str, t_render_params *render_params);
int		check_sphere(char **str, t_render_params *render_params);
int		check_plane(char **str, t_render_params *render_params);
// int		check_cone(char **str, t_render_params *render_params);

// string_utilities
t_vec3	convert_array_to_vector(char *str);
int		check_dot(char *str);

#endif