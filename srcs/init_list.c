/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 08:16:50 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 16:11:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	check_coords(t_coord **res)
{
	t_coord	*temp;
	int		comp_len;
	int		len;

	if (!*res)
		return ;
	temp = *res;
	comp_len = arr_len(temp->heights);
	while (temp)
	{
		len = arr_len(temp->heights);
		if (len != comp_len)
		{
			clear_list(res);
			return ;
		}
		temp = temp->next;
	}
}

static char	**add_heights(char *row)
{
	char	*trimmed;
	char	**spltd;

	trimmed = ft_strtrim(row, " \n");
	spltd = ft_split(trimmed, ' ');
	free(trimmed);
	return (spltd);
}

static void	add_coords(int fd, t_coord **res)
{
	char	*row;
	int		i;

	i = 0;
	row = get_next_line(fd);
	if (!row)
		return ;
	while (row)
	{
		add_node(res, create_node(i, add_heights(row)));
		free(row);
		row = get_next_line(fd);
		i++;
	}
}

t_coord	*init_list(char *file)
{
	t_coord	*result;
	int		fd;

	fd = check_file(file);
	result = NULL;
	if (fd <= 0)
		return (NULL);
	add_coords(fd, &result);
	check_coords(&result);
	if (!result)
	{
		ft_printf("Error when trying to build a wireframe\n");
		close(fd);
		return (result);
	}
	close(fd);
	return (result);
}
