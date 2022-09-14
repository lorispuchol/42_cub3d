/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_boundaries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:36:50 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/09/14 18:37:02 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mn_map_boundaries(t_game *g)
{
	t_rectangle	rect;
	int			width;

	width = 10;
	rect.tl.y = 0;
	rect.tl.x = 0;
	rect.br.y = width;
	rect.br.x = g->mn_map->width;
	ft_rectangle(g->mn_map, rect, 0xAA7dffbd);
	rect.tl.y = 0;
	rect.tl.x = 0;
	rect.br.y = g->mn_map->height;
	rect.br.x = width;
	ft_rectangle(g->mn_map, rect, 0xAA7dffbd);
	rect.tl.y = g->mn_map->height - width;
	rect.tl.x = 0;
	rect.br.y = g->mn_map->height;
	rect.br.x = g->mn_map->width;
	ft_rectangle(g->mn_map, rect, 0xAA7dffbd);
	rect.tl.y = 0;
	rect.tl.x = g->mn_map->width - width;
	rect.br.y = g->mn_map->height;
	rect.br.x = g->mn_map->width;
	ft_rectangle(g->mn_map, rect, 0xAA7dffbd);
}