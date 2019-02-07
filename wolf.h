/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/06 15:37:36 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "libft/libft.h"
# include <stdio.h>

# define PRES 128.00
# define RAD (M_PI / 180.00)
# define KEY_PLUS 69
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define SCREEN_X 800
# define SCREEN_Y 800

typedef struct		s_env
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	pretime;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double 	deltaDistY;
	double 	sideDistX;
	double 	sideDistY;
	double 	perpWallDist;
	int		x;
	int		w;
	int		mapX;
	int		mapY;
	int 	hit;
	int 	stepX;
	int 	stepY;
	int 	side;
	int 	lineHeight;
	int	 	drawStart;
	int		drawEnd;
}					t_env;

typedef struct		s_obstacle
{
	int				h;
	int				dist;
	int				token;
	int				col;
	int				x;
	int				y;
}					t_obstacle;

typedef struct		s_intersection
{
	double			x;
	double			y;
	int				dist;
	int				token;
	int				obstacle;
}					t_intersection;

typedef struct		s_player
{
	double			start_x;
	double			start_y;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			fov;
}					t_player;

typedef struct		s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*str;
	t_player	player;
	double		dist_player;
	double	xmouse;
	double	ymouse;
	int		x;
	int		y;
	int		sizel;
	int		**tab;
	double	screeny;
	double	screenx;
}					t_data;

typedef struct		s_map
{
	int		nb_lines;
	int		nb_num;
	int		i;
	int		j;
	int		**tab;
}					t_map;

void		ft_init(t_data *wolf, t_obstacle *ob);
int			**ft_verif(char *file);
void		ft_map_error(int x);
void		ft_read_error(int x);
void		ft_free_int(int **tab);
void		ft_free_char(char **dst);
int			raycasting(t_data *wolf, t_env *e, int **tab);
void		put_pixel(int x, int y, unsigned int color, t_data *wolf);
void		ft_draw(t_data *wolf, t_env e, int x);
int			ft_ray(t_data wolf);
int				wall_detection(t_obstacle *ob, t_data wolf, double alpha);
t_intersection	find_intersection_ver(double alpha, t_data wolf, int obstacle);
t_intersection	find_intersection_hor(double alpha, t_data wolf, int obstacle);
void	put_pixel_image(int x, int y, int color, t_data *wolf);
void	draw(int x, t_data *wolf, t_obstacle ob);
void	*thread1(void *param);
void	*thread2(void *param);
void	*thread3(void *param);
void	*thread4(void *param);
void	*thread5(void *param);
void	*thread6(void *param);
void	*thread7(void *param);
void	*thread8(void *param);

#endif
