/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:46:02 by bde-meij          #+#    #+#             */
/*   Updated: 2023/06/05 17:48:59 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static const char	*g_error_messages[] = {
	"Invalid number of arguments",
	"Unusable file, '*.rt' and access rights required",
	"Value is out of range",
	"Cannot identify object",
	"An object is incorrectly formatted",
	"Does not contain proper filmset (C, A and L)",
	"Malloc has failed us",
	"Argument was NULL",
	"Mlx has failed us",
};

void	print_error(t_parse_errors error_code)
{
	printf("Error\n");
	printf("%s\n", g_error_messages[error_code]);
}

void	*protec(void *ptr)
{
	if (ptr == NULL)
	{
		print_error(MALLOC_ER);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

int	check_file(char *file_name)
{
	int	i;
	int	len;

	if (!file_name)
		return (1);
	len = ft_strlen(file_name);
	i = len - 1;
	while (file_name[i] != '/' && i > 0)
		i--;
	if (file_name[i] == '/')
		i++;
	if (len - i < 4)
		return (1);
	if ((file_name[len -3] != '.') || (file_name[len -2] != 'r') || \
		(file_name[len -1] != 't'))
		return (1);
	return (0);
}

int	checkiftof(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || \
		(str[i] == '-' && i == 0))
		i++;
	if (i != ft_strlen(str) || check_dot(str) > 1)
		return (1);
	return (0);
}

int	check_value_range(char *str, double min, double max, int expected_len)
{
	char	**dub_array;
	int		i;
	int		j;

	dub_array = protec(ft_split(str, ','));
	i = 0;
	j = ft_dstrlen(dub_array);
	if (j != expected_len)
		return (1);
	while (i < j)
	{
		if (checkiftof(dub_array[i]))
		{
			ft_dstrfree(dub_array);
			return (1);
		}
		if (ft_atof(dub_array[i]) < min || ft_atof(dub_array[i]) > max)
		{
			ft_dstrfree(dub_array);
			return (1);
		}
		i++;
	}
	ft_dstrfree(dub_array);
	return (0);
}
