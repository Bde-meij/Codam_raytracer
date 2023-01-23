/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 15:57:31 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/11/24 15:21:44 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_int.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy_gnl(void *dst, const void *src, size_t n)
{
	void	*_dst;

	if (src == dst)
		return (dst);
	_dst = dst;
	while (n > 0)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		n--;
	}
	return (_dst);
}

char	*lst_fd_get_data(const t_list *lst, int fd)
{
	while (lst != NULL)
	{
		if (lst->fd == fd)
			return (lst->str);
		lst = lst->next;
	}
	return (NULL);
}

void	lst_rm_fd(t_list **lst, int fd)
{
	t_list	*tmp;
	t_list	*to_it;

	while (*lst != NULL && (*lst)->fd == fd)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
	to_it = *lst;
	while (to_it != NULL && to_it->next != NULL)
	{
		if (to_it->next->fd == fd)
		{
			tmp = to_it->next->next;
			free(to_it->next->str);
			free(to_it->next);
			to_it->next = tmp;
		}
		to_it = to_it->next;
	}
}

int	lst_fd_update_data(t_list **lst, int fd, char **str)
{
	t_list	*new;

	if (*str == NULL)
		lst_rm_fd(lst, fd);
	else
	{
		new = malloc(sizeof(t_list));
		if (new == NULL)
		{
			free(*str);
			*str = NULL;
			return (-1);
		}
		new->fd = fd;
		new->str = *str;
		new->next = *lst;
		*lst = new;
	}
	return (0);
}
