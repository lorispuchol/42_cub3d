/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_boundaries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:36:50 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/09/14 20:02:31 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_create_mini_map_2(t_game *g)
{
	ft_display_screen(g);
	if (g->key->mn_map == 1)
		mlx_put_image_to_window(g->mlx_ptr,
			g->mlx_window, g->mn_map->img, g->w_wi - g->mn_map->width - 10, 10);
}

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
