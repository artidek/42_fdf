/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:16:21 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 21:26:18 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static float	scale_factor(int size, int len)
{
	float	res;

	res = (float)size / (float)len;
	if (res / 2.5 < 1)
		return (1.0);
	else
		return (res / 2.5);
}

static t_pix	isometric(t_pix xy, t_step_coord coord, float z, float z1)
{
	t_pix	temp;
	float	x;
	float	x1;
	float	y;
	float	y1;

	temp = xy;
	x = ((float)(temp.y - temp.x)) * cos(0.523599);
	x1 = ((float)(temp.y1 - temp.x1)) * cos(0.523599);
	y = ((float)(temp.y + temp.x)) * sin(0.523599) - z;
	y1 = ((float)(temp.y1 + temp.x1)) * sin(0.523599) - z1;
	xy.x = (int)round(x * scale_factor(640, coord.width));
	xy.x1 = (int)round(x1 * scale_factor(640, coord.width));
	xy.y = (int)round(y * scale_factor(480, coord.height));
	xy.y1 = (int)round(y1 * scale_factor(480, coord.height));
	xy.x += 640;
	xy.x1 += 640;
	xy.y += 480;
	xy.y1 += 480;
	return (xy);
}

static void	bresenham(t_pix xy, t_addr *addrs, t_step_coord coords)
{
	t_pix	temp;
	float	z;
	float	z1;

	z = ((float)(coords.z_matrix)[xy.y][xy.x]);
	z1 = ((float)(coords.z_matrix)[xy.y1][xy.x1]);
	xy.color = (coords.colors)[xy.y][xy.x];
	temp = isometric(xy, coords, z, z1);
	draw_line(temp, addrs);
}

void	draw_map(t_addr *addrs, t_step_coord coords)
{
	t_pix	xy;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < coords.height - 1)
	{
		while (x < coords.width - 1)
		{
			xy.x = x;
			xy.x1 = x + 1;
			xy.y = y;
			xy.y1 = y;
			bresenham(xy, addrs, coords);
			xy.x = x;
			xy.x1 = x;
			xy.y = y;
			xy.y1 = y + 1;
			bresenham(xy, addrs, coords);
			x++;
		}
		x = 0;
		y++;
	}
}
