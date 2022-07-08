/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:12:46 by lpuchol           #+#    #+#             */
/*   Updated: 2022/07/08 15:23:03 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_free_rays(t_game *game)
{
	if (game->ray)
		free (game->ray);
}

void ft_free_key(t_game *game)
{
	if (game->key)
		free (game->key);
}


void	ft_free_mn_map(t_game *game)
{
	if (game->mn_map)
	{
		if (game->mn_map->img)
			free(game->mn_map->img);
		if (game->mn_map->addr)
			free(game->mn_map->addr);
		free(game->mn_map);
	}
}

void	ft_free_player(t_game *game)
{
	if (game->player)
		free(game->player);
}

void	ft_free_graph(t_game *game)
{
	if (game->graph)
	{
		if (game->graph->east)
			free(game->graph->east);
		if (game->graph->north)
			free(game->graph->north);
		if (game->graph->west)
			free(game->graph->west);
		if (game->graph->south)
			free(game->graph->south);
		free(game->graph);
	}
}

void	ft_free_game(t_game *game)
{
	if (game)
	{
		ft_free_graph(game);
		ft_free_player(game);
		ft_free_mn_map(game);
		l_free_tab(game->map);
		ft_free_key(game);
		ft_free_rays(game);
		free(game);
		game = NULL;
	}
}
