/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:28:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 16:21:26 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	base_val(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int	atob(char *num)
{
	int	res;
	int	hexval;
	int	i;

	res = 0;
	i = 0;
	while (num[i])
	{
		hexval = base_val(num[i], "0123456789abcdef");
		res = res * 16 + hexval;
		i++;
	}
	return (res);
}
