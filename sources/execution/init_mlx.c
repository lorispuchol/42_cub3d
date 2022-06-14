/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:57:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/15 00:04:36 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/cub3d.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_ptr, game->w_width,
			game->w_height, "cub3D");
	mlx_hook(game->mlx_window, 17, 1L << 17, ft_exit_game, game);
	mlx_loop(game->mlx_ptr);
}
