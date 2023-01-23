/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reallocf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:36:43 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/04 21:36:43 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_reallocf(void *old, size_t oldsize, size_t newsize)
{
	void	*ret;

	ret = malloc(newsize);
	if (ret == NULL)
	{
		free(old);
		return (NULL);
	}
	ft_memcpy(ret, old, oldsize);
	free(old);
	return (ret);
}
