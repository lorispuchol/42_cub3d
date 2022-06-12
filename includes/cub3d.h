/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:08:21 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/12 17:28:04 by kmammeri         ###   ########.fr       */
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
	int			w_height;
	int			w_width;
}				t_game;

//cub3d.c
void	ft_print_error(char *err, t_game *game);

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

// get_map.c
void	ft_get_map(char *line, int fd, t_game *game);

// init_game.c
void	ft_init_game(t_game *game);

#endif