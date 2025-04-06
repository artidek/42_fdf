/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:40:17 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 14:27:19 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/libftprintf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <linux/input-event-codes.h>
# include <linux/input.h>
# include <math.h>

# define M_PI 3.14159265358979323846

typedef struct s_coord
{
	int				y;
	char			**heights;
	struct s_coord	*next;
}					t_coord;

typedef struct s_addr
{
	void			*mlx;
	void			*win;
}					t_addr;

typedef struct s_step_coord
{
	int				height;
	int				width;
	int				**colors;
	int				**z_matrix;
}					t_step_coord;

typedef struct s_pix
{
	int				x;
	int				x1;
	int				y;
	int				y1;
	int				color;
}					t_pix;

int					check_file(char *file);
int					is_digits(char **arr);
int					is_ints(char **arr);
int					arr_len(char **arr);
int					trgb(int t, int r, int g, int b);
int					atob(char *num);
long long int		ft_atoil(const char *str);
void				add_node(t_coord **lst, t_coord *new);
void				clear_list(t_coord **lst);
void				start_window(t_step_coord coords);
void				min_xy(int *x, int *y, int **icoord);
void				draw_map(t_addr *addrs, t_step_coord coords);
void				draw_line(t_pix xy, t_addr *addr);
void				lst_add(t_step_coord **lst, t_step_coord *new);
void				lst_clear(t_step_coord **lst);
t_coord				*create_node(int y, char **height);
t_coord				*init_list(char *file);
t_coord				*last_node(t_coord *lst);
t_step_coord		*lst_create(int y, int x, int z, int color);
t_step_coord		create_coords(t_coord *coords);

#endif
