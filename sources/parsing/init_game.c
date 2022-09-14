/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:33:48 by lpuchol           #+#    #+#             */
/*   Updated: 2022/09/14 18:49:58 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_player(t_game *game)
{
	game->player = ft_xmalloc(sizeof(t_player));
	game->player->x = -1;
	game->player->y = -1;
	game->player->dir = -1;
	game->player->tilt = 0;
	game->player->speed = SPEED_INIT;
	game->player->acc = 0;
}

void	ft_init_graph(t_game *game)
{
	game->graph = ft_xmalloc(sizeof(t_graph));
	game->graph->north = NULL;
	game->graph->south = NULL;
	game->graph->east = NULL;
	game->graph->west = NULL;
	game->graph->sp_no = ft_xmalloc(sizeof(t_data));
	game->graph->sp_so = ft_xmalloc(sizeof(t_data));
	game->graph->sp_ea = ft_xmalloc(sizeof(t_data));
	game->graph->sky = ft_xmalloc(sizeof(t_data));
	game->graph->sky->img = NULL;
	game->graph->sky->addr = NULL;
	game->graph->ground = ft_xmalloc(sizeof(t_data));
	game->graph->ground->img = NULL;
	game->graph->ground->addr = NULL;
	game->graph->sp_we = ft_xmalloc(sizeof(t_data));
	game->graph->floor = 0xFF000000;
	game->graph->ceiling = 0xFF000000;
}

void	ft_init_key(t_game *game)
{
	game->key = ft_xmalloc(sizeof(t_key));
	game->key->down = 0;
	game->key->left = 0;
	game->key->right = 0;
	game->key->up = 0;
	game->key->lock_mouse = 0;
	game->key->rot_left = 0;
	game->key->hide_show_mouse = 1;
	game->key->night_mode = 0;
	game->key->mn_map = 0;
	game->key->rot_right = 0;
}

void	ft_init_rays(t_game *game)
{
	int	i;

	game->ray = ft_xmalloc(sizeof(t_ray) * game->w_wi);
	i = -1;
	while (++i < game->w_wi)
	{
		game->ray[i].angle = 0;
		game->ray[i].dist_impact_hor = 0;
		game->ray[i].dist_impact_ver = 0;
		game->ray[i].lil_dist = 0;
		game->ray[i].pt_impact_x = 0;
		game->ray[i].pt_impact_y = 0;
		game->ray[i].wall = 0;
		game->ray[i].wall_hor = 0;
		game->ray[i].wall_ver = 0;
		game->ray[i].if_wall_hor = 0;
		game->ray[i].if_wall_ver = 0;
		game->ray[i].next_grid_hor = 0;
		game->ray[i].next_grid_ver = 0;
		game->ray[i].x_hor = 0;
		game->ray[i].y_ver = 0;
	}
}

void	ft_init_game(t_game *game)
{
	game->map = NULL;
	game->mlx_ptr = NULL;
	game->mlx_window = NULL;
	game->w_wi = WIDTH;
	game->w_he = HEIGHT;
	game->w_he_2 = game->w_he * 0.5;
	if (FOV <= 60)
		game->fov = 60 * 2 * M_PI / (long double)360;
	else if (FOV >= 140)
		game->fov = 140 * 2 * M_PI / (long double)360;
	else
		game->fov = FOV * 2 * M_PI / (long double)360;
	game->fov_2 = game->fov * 0.5;
	game->rot = M_PI_4 * ROT_SPEED / 10;
	game->r_v = (float)game->w_wi * 0.5 / tanf(game->fov_2);
	game->vert_sensi = VERTIC_SENSI;
	game->hori_sensi = HORIZ_SENSI;
	ft_init_rays(game);
	ft_init_key(game);
	ft_init_graph(game);
	ft_init_player(game);
	ft_init_mn_map(game);
	ft_init_screen(game);
}
