/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:06:00 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 21:25:10 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	flip_hor(t_step_coord *res)
{
	int	i;
	int	j;
	int	temp;
	int	tempc;

	i = 0;
	j = 0;
	while (i < res->height)
	{
		while (j < (res->width) / 2)
		{
			tempc = (res->colors)[i][j];
			temp = (res->z_matrix)[i][j];
			(res->z_matrix)[i][j] = (res->z_matrix)[i][(res->width) - j - 1];
			(res->z_matrix)[i][(res->width) - j - 1] = temp;
			(res->colors)[i][j] = (res->colors)[i][(res->width) - j - 1];
			(res->colors)[i][(res->width) - j - 1] = tempc;
			j++;
		}
		j = 0;
		i++;
	}
}

static t_step_coord	add_pix(t_coord *coords, t_step_coord res, int **colors,
		int **z_matrix)
{
	char	**spltd;
	char	**spltdx;
	int		i;

	i = 0;
	res.width = arr_len(coords->heights);
	*colors = malloc(sizeof(int) * (res.width));
	*z_matrix = malloc(sizeof(int) * (res.width));
	while (i < res.width)
	{
		if (ft_strchr((coords->heights)[i], 'x'))
		{
			spltd = ft_split((coords->heights)[i], ',');
			spltdx = ft_split(spltd[1], 'x');
			(*colors)[i] = atob(spltdx[1]);
			(*z_matrix)[i] = ft_atoi(spltd[0]);
		}
		else
		{
			(*colors)[i] = 16777215;
			(*z_matrix)[i] = ft_atoi((coords->heights)[i]);
		}
		i++;
	}
	return (res);
}

t_step_coord	create_coords(t_coord *coords)
{
	t_step_coord	res;
	t_coord			*temp;
	int				height;
	int				i;

	temp = coords;
	i = 0;
	while (temp)
	{
		height = temp->y;
		temp = temp->next;
	}
	res.height = height + 1;
	res.colors = malloc(sizeof(int *) * (height + 1));
	res.z_matrix = malloc(sizeof(int *) * (height + 1));
	(res.colors)[height] = NULL;
	(res.z_matrix)[height] = NULL;
	while (coords)
	{
		res = add_pix(coords, res, &((res.colors)[i]), &((res.z_matrix)[i]));
		i++;
		coords = coords->next;
	}
	flip_hor(&res);
	return (res);
}
