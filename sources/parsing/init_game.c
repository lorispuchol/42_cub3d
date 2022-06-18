/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:33:48 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/18 19:35:48 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mn_map(t_game *game)
{
	game->mn_map = ft_xmalloc(sizeof(t_data));
	game->mn_map->img = NULL;
	game->mn_map->addr = NULL;
	game->mn_map->b_p_pix = 0;
	game->mn_map->l_len = 0;
	game->mn_map->endian = 0;
	game->mn_map->height = game->w_wi / 11 - 11;
	game->mn_map->width = game->w_he / 7 - 9;
}

void	ft_init_player(t_game *game)
{
	game->player = ft_xmalloc(sizeof(t_player));
	game->player->x = -1;
	game->player->y = -1;
	game->player->dir = -1;
	game->player->speed = 0;
	game->player->acc = 0;
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
	game->graph->floor = 0xFF000000;
	game->graph->ceiling = 0xFF000000;
}

void	ft_init_game(t_game *game)
{
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->mlx_window = NULL;
	game->w_wi = 1920;
	game->w_he = 1080;
	ft_init_graph(game);
	ft_init_player(game);
	ft_init_mn_map(game);
}
