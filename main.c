/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:28 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/04 10:40:10 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_arr(t_step_coord *coord)
{
	int	i;

	i = 0;
	while (i < coord->height)
	{
		free(coord->colors[i]);
		free(coord->z_matrix[i]);
		i++;
	}
	free(coord->colors);
	free(coord->z_matrix);
}

int	main(int argc, char **argv)
{
	t_coord			*coords;
	t_step_coord	s_coords;

	if (argc < 2 || argc > 2)
	{
		ft_printf("Wrong number of arguments\n");
		return (1);
	}
	coords = init_list(argv[1]);
	if (!coords)
		return (1);
	s_coords = create_coords(coords);
	start_window(s_coords);
	free_arr(&s_coords);
	clear_list(&coords);
	return (0);
}
