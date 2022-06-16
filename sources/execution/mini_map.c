/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:29:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/16 20:44:41 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_set_pix(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->b_p_pix / 8));
	*(unsigned int *)dst = color;
}

// void	ft_mn_map__wall(t_game *game)
// {
// 	float	x[2];
// 	float	y[2];
// 	t_rectangle	rect;

// 	y[0] = game->player->y - 6;
// 	x[0] = game->player->x - 5;
// 	y[1] = game->player->y + 6;
// 	x[1] = game->player->x + 5;
// 	while (y[0] < y[1])
// 	{
// 		x[0] = game->player->x - 5;
// 		while (x[0] < x[1])
// 		{
// 			if (game->map[y[0]][x[0]] == "1")
// 			{
				
// 				ft_rectangle()
// 			}
// 			x[0]++;
// 		}
// 		y[0]++;
// 	})
// }

void	ft_create_mini_map(t_game *g)
{
	t_rectangle	rect;
	t_triangle	tri;

	g->mn_map->img = mlx_new_image(g->mlx_ptr, g->mn_map->width, g->mn_map->height);
	g->mn_map->addr = mlx_get_data_addr(g->mn_map->img, &g->mn_map->b_p_pix,
			&g->mn_map->l_len, &g->mn_map->endian);
	rect.tl.x = 0;
	rect.tl.y = 0;
	rect.br.x = g->mn_map->width;
	rect.br.y = g->mn_map->height;
	ft_rectangle(g->mn_map, rect, g->graph->ceiling);
	tri.a.x = 10;
	tri.a.y = 10;
	tri.b.x = 15;
	tri.b.y = 20;
	tri.c.x = 20;
	tri.c.y = 10;
	ft_triangle(g->mn_map, tri, 0x00FF0000);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->mn_map->img, g->w_wi - g->mn_map->width - 10, 10);
}
