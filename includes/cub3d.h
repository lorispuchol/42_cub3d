/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:08:21 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/03 19:56:02 by kmammeri         ###   ########.fr       */
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
	char	*north;
	char	*south;
	char	*est;
	char	*west;
	void	*sprite_n;
	void	*sprite_s;
	void	*sprite_e;
	void	*sprite_w;
	char	*str_floor;
	char	*str_ceiling;
	int		floor;
	int		ceiling;
}				t_graph;

typedef struct s_player
{
	float	x;
	float	y;
	float	dir;
}				t_player;

typedef struct s_game
{
	t_graph	*graph;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_window;
	int		w_height;
	int		w_width;
}				t_game;

//cub3d.c
void	ft_print_error(char *err);

//parsing.c
void	ft_parsing(int argc, char **argv);

// get_next_line.c
char	*get_next_line(int fd);

#endif