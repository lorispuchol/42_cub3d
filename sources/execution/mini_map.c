/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:29:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/18 20:42:12 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_set_pix(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->b_p_pix / 8));
	*(unsigned int *)dst = color;
}

void	ft_mn_map_wall(t_game *game)
{
	int			x[2];
	int			y[2];
	int			start[2];
	int			offset[2];
	t_rectangle	rect;

	y[0] = floorf(game->player->y) - 6;
	x[0] = floorf(game->player->x) - 5;
	y[1] = floorf(game->player->y) + 6;
	x[1] = floorf(game->player->x) + 5;
	offset[0] = 16 * (game->player->x - 0.5 - floorf(game->player->x));
	offset[1] = 16 * (game->player->y - 0.5 - floorf(game->player->y));
	dprintf(2, "offset : x == %d  y == %d\n", offset[0], offset[1]);
	if (y[0] < 0)
		y[0] = 0;
	if (x[0] < 0)
		x[0] = 0;
	start[0] = floorf(game->player->x) - 4;
	start[1] = floorf(game->player->y) - 5;
	dprintf(2, "----player : x == %d  y == %d\n", (int)game->player->x, (int)game->player->y);
	while (y[0] < y[1] && game->map[y[0]])
	{
		x[0] = game->player->x - 5;
		if (x[0] < 0)
			x[0] = 0;
		while (x[0] < x[1] && x[0] < (int)ft_strlen(game->map[y[0]]))
		{
			// dprintf(2, "----cnd : x == %d  y == %d\n", x[0], y[0]);
			// if (x[0] == (int)game->player->x && y[0] == (int)game->player->y)
				// dprintf(2, "------------------cnd : x == %d  y == %d\n\n\n\n", x[0], y[0]);
			if (game->map[y[0]][x[0]] == '1' && x[0] >= 0 && y[0] >= 0)
			{
				rect.tl.x = offset[0] + (x[0] - start[0]) * 16;
				rect.tl.y = offset[1] + (y[0] - start[1]) * 16;
				rect.br.x = offset[0] + rect.tl.x + 16;
				rect.br.y = offset[1] + rect.tl.y + 16;
				// dprintf(2, "boucle tl : x == %d  y == %d\n", rect.tl.x, rect.tl.y);
				// dprintf(2, "boucle br : x == %d  y == %d\n\n", rect.br.x, rect.br.y);
				if (rect.tl.x >= 0 && rect.tl.y >= 0 && rect.br.x >= 0 && rect.br.y)
					ft_rectangle(game->mn_map, rect, 0x000000FF);
			}
			x[0]++;
		}
		y[0]++;
	}
	dprintf(2, "fin\n");
}

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
	tri.a.x = 10 + g->mn_map->width / 2 - 15;
	tri.a.y = 25 + g->mn_map->height / 2 - 15;
	tri.b.x = 15 + g->mn_map->width / 2 - 15;
	tri.b.y = 15 + g->mn_map->height / 2 - 15;
	tri.c.x = 20 + g->mn_map->width / 2 - 15;
	tri.c.y = 25 + g->mn_map->height / 2 - 15;
	ft_mn_map_wall(g);
	ft_triangle(g->mn_map, tri, 0x00FF0000);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->mn_map->img, g->w_wi - g->mn_map->width - 10, 10);
}
