/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:12:46 by lpuchol           #+#    #+#             */
/*   Updated: 2022/09/21 16:13:29 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_rays(t_game *game)
{
	if (game->ray)
		free (game->ray);
}

void	ft_free_key(t_game *game)
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

void	ft_free_graph(t_game *game)
{
	if (game->graph)
	{
		if (game->graph->sp_ea)
			free(game->graph->sp_ea);
		if (game->graph->sp_we)
			free(game->graph->sp_we);
		if (game->graph->sp_no)
			free(game->graph->sp_no);
		if (game->graph->sp_so)
			free(game->graph->sp_so);
		if (game->graph->east)
			free(game->graph->east);
		if (game->graph->north)
			free(game->graph->north);
		if (game->graph->west)
			free(game->graph->west);
		if (game->graph->south)
			free(game->graph->south);
		if (game->graph->ground)
			free(game->graph->ground);
		if (game->graph->sky)
			free(game->graph->sky);
		free(game->graph);
	}
}

void	ft_free_game(t_game *game)
{
	if (game)
	{
		if (game->screen)
			free(game->screen);
		ft_free_graph(game);
		if (game->player)
			free(game->player);
		ft_free_mn_map(game);
		l_free_tab(game->map);
		ft_free_key(game);
		ft_free_rays(game);
		free(game);
		game = NULL;
	}
}
