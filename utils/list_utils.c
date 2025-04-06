/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:55:14 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/18 12:00:12 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_coord	*create_node(int y, char **height)
{
	t_coord	*new_node;

	new_node = malloc(sizeof(t_coord));
	if (!new_node)
		return (NULL);
	new_node->y = y;
	new_node->heights = height;
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_coord **lst, t_coord *new)
{
	t_coord	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	del_node(t_coord *lst)
{
	char	**temp;

	if (!lst)
		return ;
	temp = lst->heights;
	if (temp)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(lst->heights);
	}
	free(lst);
}

void	clear_list(t_coord **lst)
{
	t_coord	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del_node(*lst);
		*lst = temp;
	}
}

t_coord	*last_node(t_coord *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
