/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:44:22 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/09 09:26:35 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_key(int key_code, t_addr *addrs)
{
	if (key_code == 65307)
	{
		mlx_destroy_image(addrs->mlx, addrs->img);
		mlx_destroy_window(addrs->mlx, addrs->win);
		mlx_loop_end(addrs->mlx);
	}
	return (0);
}

static int	close_msg(t_addr *addrs)
{
	mlx_destroy_image(addrs->mlx, addrs->img);
	mlx_destroy_window(addrs->mlx, addrs->win);
	mlx_loop_end(addrs->mlx);
	return (0);
}

void	start_window(t_step_coord coords)
{
	t_addr	addreses;

	addreses.mlx = mlx_init();
	if (!addreses.mlx)
	{
		ft_printf("Failed to create connection\n");
		return ;
	}
	addreses.win = mlx_new_window(addreses.mlx, 1280, 960, "fdf");
	addreses.img = mlx_new_image(addreses.mlx, 1280, 960);
	addreses.data = mlx_get_data_addr(addreses.img, &addreses.bpp,
			&addreses.line_size, &addreses.endian);
	draw_map(&addreses, coords);
	mlx_put_image_to_window(addreses.mlx, addreses.win, addreses.img, 0, 0);
	mlx_key_hook(addreses.win, close_key, &addreses);
	mlx_hook(addreses.win, 33, 0, close_msg, &addreses);
	mlx_loop(addreses.mlx);
	mlx_destroy_display(addreses.mlx);
	free(addreses.mlx);
}
