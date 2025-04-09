/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:50:42 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/09 09:28:52 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	check_format(char *file)
{
	int		len;
	char	*compare;

	len = ft_strlen(file);
	compare = &file[len - 4];
	if (ft_strncmp(compare, ".fdf", 4) == 0)
		return (1);
	return (0);
}

int	check_file(char *file)
{
	int	fd;

	if (!check_format(file))
	{
		ft_printf("Wrong file format\n");
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("Wrong path or file doesn't exist\n");
		return (0);
	}
	return (fd);
}

void	free_c_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_ints(char **arr)
{
	char			**temparr;
	long long int	val;

	temparr = arr;
	while (*temparr)
	{
		val = ft_atoil(*temparr);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		temparr++;
	}
	return (1);
}

int	arr_len(char **arr)
{
	int	len;

	len = 0;
	if (!arr)
		return (len);
	while (arr[len])
		len++;
	return (len);
}
