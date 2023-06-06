/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filename.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 11:20:19 by jvan-kra      #+#    #+#                 */
/*   Updated: 2023/06/06 11:20:19 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_basename(const char *input)
{
	char	*last_slash;
	char	*basename;

	last_slash = ft_strrchr(input, '/');
	if (last_slash == NULL)
		return (ft_strdup(input));
	basename = ft_strdup(last_slash + 1);
	return (basename);
}
