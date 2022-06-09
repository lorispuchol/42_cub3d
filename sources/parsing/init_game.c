/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:33:48 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/09 14:19:55 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_player(t_game *game)
{
	t_player	player;

	player.x = 0;
	player.y = 0;
	player.dir = 0;
	game->player = &player;
}

void	ft_init_graph(t_game *game)
{
	t_graph	graph;

	graph.north = NULL;
	graph.south = NULL;
	graph.est = NULL;
	graph.west = NULL;
	graph.sprite_n = NULL;
	graph.sprite_s = NULL;
	graph.sprite_e = NULL;
	graph.sprite_w = NULL;
	graph.floor = 0;
	graph.ceiling = 0;
	game->graph = &graph;
}

void	ft_init_game(t_game *game)
{
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->mlx_window = NULL;
	game->w_width = 0;
	game->w_height = 0;
	ft_init_graph(game);
}