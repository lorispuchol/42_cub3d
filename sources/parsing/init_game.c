/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:33:48 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/12 13:11:01 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_player(t_game *game)
{
	game->player = ft_xmalloc(sizeof(t_player));
	game->player->x = 0;
	game->player->y = 0;
	game->player->dir = 0;
}

void	ft_init_graph(t_game *game)
{

	game->graph = ft_xmalloc(sizeof(t_graph));
	game->graph->north = NULL;
	game->graph->south = NULL;
	game->graph->east = NULL;
	game->graph->west = NULL;
	game->graph->sprite_n = NULL;
	game->graph->sprite_s = NULL;
	game->graph->sprite_e = NULL;
	game->graph->sprite_w = NULL;
	game->graph->floor = 0x00000000;
	game->graph->ceiling = 0x00000000;
}

void	ft_init_game(t_game *game)
{
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->mlx_window = NULL;
	game->w_width = 0;
	game->w_height = 0;
	ft_init_graph(game);
	ft_init_player(game);
}
