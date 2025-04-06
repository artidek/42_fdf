/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:17:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 16:26:20 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	direction(int d)
{
	if (d < 0)
		return (-1);
	else
		return (1);
}

static t_pix	check_xy(t_pix xy)
{
	int	temp;

	if (xy.x > xy.x1 || xy.y > xy.y1)
	{
		temp = xy.x;
		xy.x = xy.x1;
		xy.x1 = temp;
		temp = xy.y;
		xy.y = xy.y1;
		xy.y1 = temp;
	}
	return (xy);
}

static void	draw_line_h(t_pix xy, t_addr *addr, int dx, int dy)
{
	int	p;
	int	i;
	int	dir;
	int	y;

	dir = direction(dy);
	y = xy.y;
	dy *= dir;
	p = 2 * dy - dx;
	i = 0;
	while (i <= dx)
	{
		mlx_pixel_put(addr->mlx, addr->win, xy.x + i, y, xy.color);
		i++;
		if (p >= 0)
		{
			y += dir;
			p -= 2 * dx;
		}
		p += 2 * dy;
	}
}

static void	draw_line_v(t_pix xy, t_addr *addr, int dx, int dy)
{
	int	p;
	int	i;
	int	dir;
	int	x;

	dir = direction(dx);
	x = xy.x;
	dx *= dir;
	p = 2 * dx - dy;
	i = 0;
	while (i <= dy)
	{
		mlx_pixel_put(addr->mlx, addr->win, x, xy.y + i, xy.color);
		i++;
		if (p >= 0)
		{
			x += dir;
			p -= 2 * dy;
		}
		p += 2 * dx;
	}
}

void	draw_line(t_pix xy, t_addr *addr)
{
	if (abs(xy.x1 - xy.x) > abs(xy.y1 - xy.y))
	{
		xy = check_xy(xy);
		draw_line_h(xy, addr, xy.x1 - xy.x, xy.y1 - xy.y);
	}
	else
	{
		xy = check_xy(xy);
		draw_line_v(xy, addr, xy.x1 - xy.x, xy.y1 - xy.y);
	}
}
