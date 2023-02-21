#ifndef VEC3_H
#define VEC3_H

#ifndef VEC3_TYPE
#define VEC3_TYPE double
#endif

typedef struct s_vec3
{
	VEC3_TYPE	data[3];
}	t_vec3;

// (Constructors)
t_vec3	vec3_new(const VEC3_TYPE v1, const VEC3_TYPE v2, const VEC3_TYPE v3);
void	vec3_set(t_vec3 *vec, const VEC3_TYPE v1, const VEC3_TYPE v2, const VEC3_TYPE v3);
void	vec3_fill(t_vec3 *vec, const VEC3_TYPE val);

// (Basic calculations)
t_vec3	vec3_add(const t_vec3 *lhs, const t_vec3 *rhs);
t_vec3	vec3_add_c(const t_vec3 lhs, t_vec3 rhs);
t_vec3	vec3_subtract(const t_vec3 *lhs, const t_vec3 *rhs);
t_vec3	vec3_subtract_c(const t_vec3 lhs, const t_vec3 rhs);

t_vec3	vec3_multiply(const t_vec3 *lhs, const t_vec3 *rhs);
t_vec3	vec3_multiply_c(const t_vec3 lhs, const t_vec3 rhs);
t_vec3	vec3_scalar(const t_vec3 *lhs, const VEC3_TYPE rhs);
t_vec3	vec3_scalar_c(const t_vec3 lhs, const VEC3_TYPE rhs);
t_vec3	vec3_divide(const t_vec3 *lhs, const VEC3_TYPE rhs);
t_vec3	vec3_divide_c(const t_vec3 lhs, const VEC3_TYPE rhs);

VEC3_TYPE	vec3_dot(const t_vec3 *lhs, const t_vec3 *rhs);
VEC3_TYPE	vec3_dot_c(const t_vec3 lhs, const t_vec3 rhs);

t_vec3	vec3_cross(const t_vec3 *lhs, const t_vec3 *rhs);
t_vec3	vec3_cross_c(const t_vec3 lhs, const t_vec3 rhs);

VEC3_TYPE	vec3_lenght(const t_vec3 *lhs);
VEC3_TYPE	vec3_lenght_c(const t_vec3 lhs);

VEC3_TYPE vec3_lenght_squared(const t_vec3 *lhs);
VEC3_TYPE vec3_lenght_squared_c(const t_vec3 lhs);

t_vec3	vec3_normalize(const t_vec3 *vec);
t_vec3	vec3_normalize_c(const t_vec3 vec);


void 	vec3_print(const t_vec3 *vec);
void 	vec3_print_c(const t_vec3 vec);


#endif
