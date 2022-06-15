/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:29:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/15 18:00:13 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_set_pix(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->b_p_pix / 8));
	*(unsigned int *)dst = color;
}

void	ft_create_mini_map(t_game *g)
{
	t_rectangle	rect;

	g->mn_map->img = mlx_new_image(g->mlx_ptr, g->mn_map->width, g->mn_map->height);
	g->mn_map->addr = mlx_get_data_addr(g->mn_map->img, &g->mn_map->b_p_pix,
			&g->mn_map->l_len, &g->mn_map->endian);
	rect.tl.x = 0;
	rect.tl.y = 0;
	rect.br.x = g->mn_map->width;
	rect.br.y = g->mn_map->height;
	ft_rectangle(g->mn_map, rect, g->graph->ceiling);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->mn_map->img, g->w_wi - g->mn_map->width - 10, 10);
}
