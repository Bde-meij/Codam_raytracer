/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jellevankraaij@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:30:06 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/04/12 16:30:06 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# ifndef VEC3_TYPE
#  define VEC3_TYPE double
# endif

# include <stdbool.h>

typedef struct s_vec3
{
	VEC3_TYPE	data[3];
}	t_vec3;

// (Constructors)
t_vec3		vec3_new(const VEC3_TYPE v1, const VEC3_TYPE v2, \
	const VEC3_TYPE v3);
void		vec3_fill(t_vec3 *vec, const VEC3_TYPE val);

// (Basic calculations)
t_vec3		vec3_add(const t_vec3 *lhs, const t_vec3 *rhs);
t_vec3		vec3_add_c(const t_vec3 lhs, t_vec3 rhs);
t_vec3		vec3_subtract(const t_vec3 *lhs, const t_vec3 *rhs);
t_vec3		vec3_subtract_c(const t_vec3 lhs, const t_vec3 rhs);

t_vec3		vec3_multiply(const t_vec3 *lhs, const t_vec3 *rhs);
t_vec3		vec3_multiply_c(const t_vec3 lhs, const t_vec3 rhs);
t_vec3		vec3_scalar(const t_vec3 *lhs, const VEC3_TYPE rhs);
t_vec3		vec3_scalar_c(const t_vec3 lhs, const VEC3_TYPE rhs);
t_vec3		vec3_divide(const t_vec3 *lhs, const VEC3_TYPE rhs);
t_vec3		vec3_divide_c(const t_vec3 lhs, const VEC3_TYPE rhs);

t_vec3		vec3_reverse(const t_vec3 *vec);
t_vec3		vec3_reverse_c(const t_vec3 vec);

// (Advanced calculations)

t_vec3		vec3_clamp(const t_vec3 *vec, const VEC3_TYPE min, \
	const VEC3_TYPE max);
t_vec3		vec3_clamp_c(const t_vec3 vec, const VEC3_TYPE min, \
	const VEC3_TYPE max);

VEC3_TYPE	vec3_dot(const t_vec3 *lhs, const t_vec3 *rhs);
VEC3_TYPE	vec3_dot_c(const t_vec3 lhs, const t_vec3 rhs);

t_vec3		vec3_cross(const t_vec3 *lhs, const t_vec3 *rhs);
t_vec3		vec3_cross_c(const t_vec3 lhs, const t_vec3 rhs);

VEC3_TYPE	vec3_lenght(const t_vec3 *lhs);
VEC3_TYPE	vec3_lenght_c(const t_vec3 lhs);

VEC3_TYPE	vec3_lenght_squared(const t_vec3 *lhs);
VEC3_TYPE	vec3_lenght_squared_c(const t_vec3 lhs);

t_vec3		vec3_normalize(const t_vec3 *vec);
t_vec3		vec3_normalize_c(const t_vec3 vec);

t_vec3		vec3_reflect(const t_vec3 *v, const t_vec3 *n);
t_vec3		vec3_reflect_c(const t_vec3 v, const t_vec3 n);

// (Comparisons)
bool		vec3_eq(const t_vec3 *lhs, const t_vec3 *rhs);
bool		vec3_eq_c(const t_vec3 lhs, const t_vec3 rhs);

// (Utilities)
void		vec3_print(const t_vec3 *vec);
void		vec3_print_c(const t_vec3 vec);

#endif
