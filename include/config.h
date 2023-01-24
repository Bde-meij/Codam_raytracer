#ifndef CONFIG_H
# define CONFIG_H

// brug parse / rend

# include <stdint.h>
# include <libft.h>

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

typedef enum e_objectType
{
	SPHERE,
	PLANE,
	CYLINDER,
} t_objectType;


typedef struct s_object
{
	t_objectType type;
	double cords[3];
	double orient[3];
	uint8_t color[3];

	void *data;
	bool (*parser)(struct s_object *obj, char *input);
	// double *(*intersect)(t_object *obj, t_ray *ray);
}	t_object;

typedef struct s_camera
{
	double cords[3];
	double orient[3];
	uint8_t	fov;
}	t_camera;

typedef struct s_lightSource
{
	double ratio;
	uint8_t color[3];
	double cords[3];
}	t_lightSource;

typedef struct s_config
{
	double light_cords[3];

	t_lightSource	ambientLight;
	t_lightSource	lightPoint;

	t_camera		camera;

	t_list			*objects;
}	t_config;

#endif