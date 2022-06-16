/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:08:21 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/16 13:13:49 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
	float	x;
	float	y;
	float	dir;
}				t_player;

typedef struct s_game
{
	t_graph		*graph;
	t_player	*player;
	char		**map;
	void		*mlx_ptr;
	void		*mlx_window;
	t_data		*mn_map;
	t_data		*screen;
	int			w_he;
	int			w_wi;
	int			fov;
	float		r_h;
	float		r_v;
}				t_game;

// free.c
void	ft_free_game(t_game *game);

//cub3d.c
void	ft_print_error(char *err, t_game *game);
int		ft_exit_game(t_game *game);

//parsing.c
void	ft_parsing(int argc, char **argv, t_game *game);

// get_next_line.c
char	*get_next_line(int fd);

// utils.c
int		l_free_tab(char **tab);
void	*ft_xmalloc(size_t size);
char	*l_add_char(char *str, char c);

// check_file.c
int		empty_line(char *line);

// get_data_map.c
int		ft_get_textures(char *line, t_game *game);
void	l_non_null_value(t_game *game);

// get_data_map_2.c
int		ft_forward_in_color(char *line, int i, t_game *game);
void	ft_forward_in_color_2(char *line, int i, t_game *game);

// get_map.c
void	ft_get_map(char *line, int fd, t_game *game);

// check_map.c
void	ft_check_map(t_game *game);

// init_game.c
void	ft_init_game(t_game *game);

// check_map_closed.c
void	ft_check_open_map(t_game *game, int x, int y);
void	ft_square_map(t_game *game);

// init_mlx.c
void	ft_init_mlx(t_game *game);

// mini_map.c
void	ft_create_mini_map(t_game *g);
void	ft_set_pix(t_data *data, int x, int y, int color);

// geometrie.c
void	ft_vertical_line(t_data *img, t_2dpoint top, t_2dpoint bot, int color);
void	ft_rectangle(t_data *img, t_rectangle rect, int color);

#endif