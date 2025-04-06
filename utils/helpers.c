/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:50:42 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 16:19:41 by aobshatk         ###   ########.fr       */
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

int	is_digits(char **arr)
{
	int		i;
	int		j;
	char	**temparr;

	i = 0;
	j = 0;
	temparr = arr;
	while (temparr[j])
	{
		while (temparr[j][i])
		{
			if (!ft_isdigit(temparr[j][i]) && temparr[j][i] != '-')
				return (0);
			if (temparr[j][i] == '-' && !temparr[j][i + 1])
				return (0);
			if (temparr[j][i] == '-' && !ft_isdigit(temparr[j][i + 1]))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
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
