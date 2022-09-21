/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:43:18 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/09/21 15:45:20 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_destroy_walls(t_game *game)
{
	if (game->graph->sp_ea->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->sp_ea->img);
	if (game->graph->sp_so->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->sp_so->img);
	if (game->graph->sp_no->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->sp_no->img);
	if (game->graph->sp_we->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->sp_we->img);
	if (game->graph->ground->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->ground->img);
}

void	ft_destroy(t_game *g)
{
	if (g->key->animated_sprite && g->graph->sp_ea->img && g->graph->sp_we->img
		&& g->graph->sp_no->img && g->graph->sp_so->img)
	{
		mlx_destroy_image(g->mlx_ptr, g->graph->sp_ea->img);
		mlx_destroy_image(g->mlx_ptr, g->graph->sp_no->img);
		mlx_destroy_image(g->mlx_ptr, g->graph->sp_so->img);
		mlx_destroy_image(g->mlx_ptr, g->graph->sp_we->img);
		ft_sprite_to_img(g);
	}
}

void	ft_new_image(t_game *g, t_data *sp_wall, char *str)
{
	sp_wall->img = mlx_xpm_file_to_image(g->mlx_ptr, str,
			&sp_wall->width, &sp_wall->height);
	sp_wall->r_h = 0.5 * g->r_v / sp_wall->width;
	sp_wall->addr = mlx_get_data_addr(sp_wall->img,
			&sp_wall->b_p_pix, &sp_wall->l_len, &sp_wall->endian);
}

		// g->graph->sp_ea->img = mlx_xpm_file_to_image(g->mlx_ptr, str,
		// 		&g->graph->sp_ea->width, &g->graph->sp_ea->height);
		// g->graph->sp_ea->r_h = 0.5 * g->r_v / g->graph->sp_ea->width;
		// g->graph->sp_ea->addr = mlx_get_data_addr(g->graph->sp_ea->img,
		// 		&g->graph->sp_ea->b_p_pix, &g->graph->sp_ea->l_len,
		// 		&g->graph->sp_ea->endian);
