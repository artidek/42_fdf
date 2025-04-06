/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:51:44 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/01 20:47:14 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*int	get_z(t_step_coord *coord, float x, float y)
{
	while (coord)
	{
		if (coord->y == (int)y && coord->x == (int)x)
			return (coord->z);
		coord = coord->next;
	}
	return (0);
}*/
