/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:47:14 by bde-meij          #+#    #+#             */
/*   Updated: 2023/04/20 14:48:29 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <stdio.h>

t_vec3	convert_array_to_vector(char *str)
{
	char	**tmp_strs;
	t_vec3	new_vector;

	tmp_strs = protec(ft_split(str, ','));
	new_vector = vec3_new(ft_atof(tmp_strs[0]), ft_atof(tmp_strs[1]), \
		ft_atof(tmp_strs[2]));
	ft_dstrfree(tmp_strs);
	return (new_vector);
}

int	check_dot(char *str)
{
	int	i;
	int	dots;

	i = 0;
	dots = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dots++;
		i++;
	}
	return (dots);
}
