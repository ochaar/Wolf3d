/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by ochaar            #+#    #+#             */
/*   Updated: 2019/03/15 17:07:27 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "../libft/include/libft.h"
# include <stdio.h>

# define PRES 128.00
# define RAD (M_PI / 180.00)
# define KEY_PLUS 69
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define SPACE 49
# define SCREEN_X 800
# define SCREEN_Y 800

typedef struct		s_obstacle
{
	int				h;
	double			dist;
	int				token;
	int				col;
	int				ori;
	int				x;
	int				y;
}					t_obstacle;

typedef struct		s_intersection
{
	double			x;
	double			y;
	double			dist;
	int				token;
	int				obstacle;
}					t_inter;

typedef struct		s_player
{
	double		start_x;
	double		start_y;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		fov;
}					t_player;

typedef struct		s_tex
{
	void		*img;
	char		*str;
	int			sizel;
}					t_tex;

typedef struct		s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str;
	t_tex		tex[7];
	t_player	player;
	double		proj_dist_player;
	int			saut;
	int			menu;
	int			enter;
	int			x;
	int			y;
	int			speed;
	int			sizel;
	int			**tab;
	double		screeny;
	double		screenx;
}					t_data;

typedef struct		s_map
{
	int		nb_lines;
	int		nb_num;
	int		i;
	int		j;
	int		**tab;
}					t_map;

typedef struct		s_worker_arg
{
	t_data			*wolf;
	int				start;
}					t_worker_arg;

void				ft_init(t_data *wolf);
int					**ft_verif(char *file);
void				ft_map_error(int x, int line);
void				ft_read_error(int x);
void				ft_free_int(int **tab);
void				ft_free_char(char **dst);
int					ft_raycast(t_data wolf);
int					ft_wall_detect(t_obstacle *ob, t_data wolf, double alpha);
t_inter				ft_vertical(double alpha, t_data wolf, int obstacle);
t_inter				ft_horizontal(double alpha, t_data wolf, int obstacle);
void				ft_put_pixel(int x, int y, int color, const t_data *wolf);
void				draw(int x, const t_data *wolf, t_obstacle ob);
void				ft_load_wall(t_data	*wolf);
void				ft_print_sky(int x, const t_data *wolf);
void				ft_move(int key, t_data *wolf);
int					menu(t_data *wolf);
void				hook_key_menu(int key, t_data *wolf);
void				*thread(t_worker_arg *arg);
void				ft_mini_map(t_data wolf);

#endif
