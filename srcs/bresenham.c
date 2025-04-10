/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:17:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/10 23:13:32 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void draw_line(t_pix xy, t_addr *addr)
{
	int dx = abs(xy.x1 - xy.x);
	int dy = abs(xy.y1 - xy.y);
	int sx = (xy.x1 > xy.x) ? 1 : -1;
	int sy = (xy.y1 > xy.y) ? 1 : -1;
	int err = dx - dy;
	int err2;

	while (1)
	{
		int pix_addr = (xy.y * addr->line_size) + (xy.x * (addr->bpp / 8));
		addr->data[pix_addr] = (xy.color) & 0xFF;
		addr->data[pix_addr + 1] = (xy.color >> 8) & 0xFF;
		addr->data[pix_addr + 2] = (xy.color >> 16) & 0xFF;

		if (xy.x == xy.x1 && xy.y == xy.y1)
			break;

		err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			xy.x += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			xy.y += sy;
		}
	}
}
