/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:44:22 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 21:46:40 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_key(int key_code, t_addr *addrs)
{
	if (key_code == 65307)
	{
		mlx_destroy_window(addrs->mlx, addrs->win);
		mlx_loop_end(addrs->mlx);
	}
	return (0);
}

static int	close_msg(t_addr *addrs)
{
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
	draw_map(&addreses, coords);
	mlx_key_hook(addreses.win, close_key, &addreses);
	mlx_hook(addreses.win, 33, 0, close_msg, &addreses);
	mlx_loop(addreses.mlx);
	free(addreses.mlx);
}
