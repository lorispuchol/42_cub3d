/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:08:21 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/03 17:09:41 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct s_data
{
	void	*sprite_n;
	void	*sprite_s;
	void	*sprite_e;
	void	*sprite_w;
	int		floor;
	int		ceiling;
}				t_data;

typedef struct s_player
{
	float	x;
	float	y;
}				t_player;

typedef struct s_game
{
	t_data	*data;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_window;
	int		w_height;
	int		w_width;
}				t_game;

#endif