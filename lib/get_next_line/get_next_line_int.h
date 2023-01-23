/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_int.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 20:59:24 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/11/24 15:01:15 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_INT_H
# define GET_NEXT_LINE_INT_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_gnl {
	char	*buf;
	char	*ret;
	size_t	len;
	size_t	nl;
}	t_gnl;

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen_gnl(const char *s);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*lst_fd_get_data(const t_list *lst, int fd);
void	lst_rm_fd(t_list **lst, int fd);
int		lst_fd_update_data(t_list **lst, int fd, char **str);

#endif