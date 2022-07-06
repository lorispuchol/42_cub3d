/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:08:21 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/06 21:12:59 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define HEIGHT 540
# define WIDTH 960
# define FOV 60
# define SPEED_INIT 0.06
# define FACTOR_SPEED_SIDE 0.6
# define FACTOR_SPEED_BACK 0.4
# define FACTOR_SPEED_SPRINT 2
# define CURSOR_COEFA 4
# define CURSOR_COEFB 8
# define CURSOR_COEFC 3
# define MNM_DP_SQR_X 6
# define MNM_DP_SQR_Y 7
# define MNM_PIX_SQR 20
# define CURS_OFFSETX 0.465
# define CURS_OFFSETY 0.465
# define MNP_GRID 2

enum sprite {
	SP_NORTH,
	SP_SOUTH,
	SP_EAST,
	SP_WEST,
};

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_2dpoint
{
	int	x;
	int	y;
}			t_2dpoint;

typedef struct s_rectangle
{
	t_2dpoint	tl;
	t_2dpoint	br;
}			t_rectangle;

typedef struct s_triangle
{
	t_2dpoint	a;
	t_2dpoint	b;
	t_2dpoint	c;
}			t_triangle;

typedef struct s_ray
{
	long double	angle;
	float		pt_impact_x;
	float		pt_impact_y;
	float		dist_impact_hor;
	float		dist_impact_ver;
	float		lil_dist;
	int			wall_hor;
	int			wall_ver;
	int			if_wall_ver;
	int			if_wall_hor;
	int			wall;
	int			next_grid_hor;
	int			next_grid_ver;
	float		y_ver;
	float		x_hor;
}			t_ray;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		b_p_pix;
	int		l_len;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rot_left;
	int	rot_right;
}				t_key;
typedef struct s_graph
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	void				*sprite_n;
	void				*sprite_s;
	void				*sprite_e;
	void				*sprite_w;
	unsigned int		floor;
	unsigned int		ceiling;
}				t_graph;

typedef struct s_player
{
	float		x;
	float		y;
	long double	dir;
	float		speed;
	float		acc;
}				t_player;

typedef struct s_game
{
	t_graph		*graph;
	t_player	*player;
	t_key		*key;
	t_ray		*ray;
	char		**map;
	int			l_map;
	int			h_map;
	void		*mlx_ptr;
	void		*mlx_window;
	t_data		*mn_map;
	t_data		*screen;
	int			w_he;
	int			w_wi;
	float		fov;
	float		fov_2;
	long double	angle_rays;
	float		r_v;
	long double	rot;
	int			mn_map_pix_sqr;
}				t_game;

// free.c
void		ft_free_game(t_game *game);

//cub3d.c
void		ft_print_error(char *err, t_game *game);
int			ft_exit_game(t_game *game);

//parsing.c
void		ft_parsing(int argc, char **argv, t_game *game);

// get_next_line.c
char		*get_next_line(int fd);

// utils.c
int			l_free_tab(char **tab);
void		*ft_xmalloc(size_t size);
char		*l_add_char(char *str, char c);

// check_file.c
int			empty_line(char *line);

// get_data_map.c
int			ft_get_textures(char *line, t_game *game);
void		l_non_null_value(t_game *game);

// get_data_map_2.c
int			ft_forward_in_color(char *line, int i, t_game *game);
void		ft_forward_in_color_2(char *line, int i, t_game *game);

// get_map.c
void		ft_get_map(char *line, int fd, t_game *game);

// check_map.c
void		ft_check_map(t_game *game);

// init_game.c
void		ft_init_game(t_game *game);

// check_map_closed.c
void		ft_check_open_map(t_game *game, int x, int y);
void		ft_square_map(t_game *game);

// init_mlx.c
void		ft_init_mlx(t_game *game);

// mini_map.c
void		ft_create_mini_map(t_game *g);
void		ft_set_pix(t_data *data, int x, int y, int color);
void		ft_wall_boundary_x(t_game *g, int x, t_rectangle *rect);
void		ft_wall_boundary_y(t_game *g, int y, t_rectangle *rect);

// geometrie.c
void		ft_vertical_line(t_data *img,
				t_2dpoint top, t_2dpoint bot, int color);
void		ft_rectangle(t_data *img, t_rectangle rect, int color);
void		ft_put_triangle(t_data *img, t_triangle trgl, int color);

// mouvement.c
void		ft_up(t_game *game);
void		ft_down(t_game *game);
void		ft_right(t_game *game);
void		ft_left(t_game *game);

// player_action.c
int			ft_press_key(int keycode, t_game *game);
int			ft_release_key(int keycode, t_game *game);
int			ft_action_loop(t_game *game);

// minimap_utils.c
t_triangle	ft_set_triangle(t_game *g, int side);
void		ft_mn_map_wall(t_game *g);

// geometry_utils.c
void		ft_increment_triangle(t_rectangle *l,
				int *x0, int *x1, t_triangle *t);
void		ft_innit_triangle(t_rectangle *l, t_triangle *t, int *b0, int *b1);

// init_ray.c
void		ft_init_ray(t_game *game);
void		ft_cast_ray(t_game *game);
void		check_if_wall_ver(int next_grid_ver, float y_ver, t_ray *ray, t_game *game);
void		check_if_wall_hor(int next_grid_hor, float x_hor, t_ray *ray, t_game *game);



// display_screen.c
void		ft_display_screen(t_game *g);

// raycast.c

void	ft_raycast_btm_rgt(t_game *g, t_ray *ray);
void	ft_raycast_btm_lft(t_game *g, t_ray *ray);
void	ft_raycast_top_lft(t_game *g, t_ray *ray);
void	ft_raycast_top_rgt(t_game *g, t_ray *ray);

#endif