/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:29:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/28 02:26:17 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

void	ft_set_pix(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->b_p_pix / 8));
	*(unsigned int *)dst = color;
}

// void	ft_mn_map_wall(t_game *game)
// {
// 	int			x[2];
// 	int			y[2];
// 	int			start[2];
// 	int			offset[2];
// 	t_rectangle	rect;

// 	y[0] = floorf(game->player->y) - 6;
// 	x[0] = floorf(game->player->x) - 5;
// 	y[1] = floorf(game->player->y) + 6;
// 	x[1] = floorf(game->player->x) + 5;
// 	offset[0] = 16 * (game->player->x - 0.5 - floorf(game->player->x));
// 	offset[1] = 16 * (game->player->y - 0.5 - floorf(game->player->y));
// 	dprintf(2, "offset : x == %d  y == %d\n", offset[0], offset[1]);
// 	if (y[0] < 0)
// 		y[0] = 0;
// 	if (x[0] < 0)
// 		x[0] = 0;
// 	start[0] = floorf(game->player->x) - 4;
// 	start[1] = floorf(game->player->y) - 5;
// 	dprintf(2, "----player : x == %d  y == %d\n", (int)game->player->x, (int)game->player->y);
// 	while (y[0] < y[1] && game->map[y[0]])
// 	{
// 		x[0] = game->player->x - 5;
// 		if (x[0] < 0)
// 			x[0] = 0;
// 		while (x[0] < x[1] && x[0] < (int)ft_strlen(game->map[y[0]]))
// 		{
// 			// dprintf(2, "----cnd : x == %d  y == %d\n", x[0], y[0]);
// 			// if (x[0] == (int)game->player->x && y[0] == (int)game->player->y)
// 				// dprintf(2, "------------------cnd : x == %d  y == %d\n\n\n\n", x[0], y[0]);
// 			if (game->map[y[0]][x[0]] == '1' && x[0] >= 0 && y[0] >= 0)
// 			{
// 				rect.tl.x = offset[0] + (x[0] - start[0]) * 16;
// 				rect.tl.y = offset[1] + (y[0] - start[1]) * 16;
// 				rect.br.x = offset[0] + rect.tl.x + 16;
// 				rect.br.y = offset[1] + rect.tl.y + 16;
// 				// dprintf(2, "boucle tl : x == %d  y == %d\n", rect.tl.x, rect.tl.y);
// 				// dprintf(2, "boucle br : x == %d  y == %d\n\n", rect.br.x, rect.br.y);
// 				if (rect.tl.x >= 0 && rect.tl.y >= 0 && rect.br.x >= 0 && rect.br.y)
// 					ft_rectangle(game->mn_map, rect, 0x00888888);
// 			}
// 			x[0]++;
// 		}
// 		y[0]++;
// 	}
// 	dprintf(2, "fin\n");
// }

void	ft_mn_map_wall(t_game *game)
{
	int			x[2];
	int			y[2];
	int			offset[2];
	t_rectangle	rect;

	y[0] = (int)game->player->y - MNM_DP_SQR_Y;
	y[1] = 0;
	while (y[0] < 0)
	{
		y[0]++;
		y[1]++;
	}
	while (game->map[y[0]] && y[0] - 1 <= (int)roundf(game->player->y) + MNM_DP_SQR_Y && y[1] * MNM_PIX_SQR <= game->mn_map->height - MNM_PIX_SQR)
	{
		x[0] = (int)game->player->x - MNM_DP_SQR_X;
		x[1] = 0;
		while (x[0] < 0)
		{
			x[0]++;
			x[1]++;
		}
		while (game->map[y[0]][x[0]] && x[0] <= (int)roundf(game->player->x) + MNM_DP_SQR_X && x[1] * MNM_PIX_SQR <= game->mn_map->width - MNM_PIX_SQR)
		{
			if (game->map[y[0]][x[0]] == '1' && game->map[y[0]][x[0]])
			{
				offset[0] = (int)floorf((game->player->x - floorf(game->player->x)) * 10);
				offset[1] = (int)floorf((game->player->y - floorf(game->player->y)) * 10);
				if (offset[0] < 0 || offset[0] > 9)
					offset[0] = 0;
				if (offset[1] < 0 || offset[1] > 9)
					offset[1] = 0;
				rect.tl.x = x[1] * MNM_PIX_SQR - offset[0] * 0.1 * MNM_PIX_SQR + CURS_OFFSETX * MNM_PIX_SQR;
				if (rect.tl.x < 0)
					rect.tl.x = 0;
				if (rect.tl.x > game->mn_map->width)
					rect.tl.x = game->mn_map->width;
				rect.tl.y = y[1] * MNM_PIX_SQR - offset[1] * 0.1 * MNM_PIX_SQR + CURS_OFFSETY * MNM_PIX_SQR;
				if (rect.tl.y < 0)
					rect.tl.y = 0;
				if (rect.tl.y > game->mn_map->height)
					rect.tl.y = game->mn_map->height;
				rect.br.x = x[1] * MNM_PIX_SQR + MNM_PIX_SQR - offset[0] * 0.1 * MNM_PIX_SQR + CURS_OFFSETX * MNM_PIX_SQR - MNP_GRID;
				if (rect.br.x < 0)
					rect.br.x = 0;
				if (rect.br.x > game->mn_map->width)
					rect.br.x = game->mn_map->width;
				rect.br.y = y[1] * MNM_PIX_SQR + MNM_PIX_SQR - offset[1] * 0.1 * MNM_PIX_SQR + CURS_OFFSETY * MNM_PIX_SQR - MNP_GRID;
				if (rect.br.y < 0)
					rect.br.y = 0;
				if (rect.br.y > game->mn_map->height)
					rect.br.y = game->mn_map->height;
				ft_rectangle(game->mn_map, rect, 0x00AAAAAA);
			}
			if (game->map[y[0]][x[0]] == '0')
			{
				offset[0] = (int)floorf((game->player->x - floorf(game->player->x)) * 10);
				offset[1] = (int)floorf((game->player->y - floorf(game->player->y)) * 10);
				if (offset[0] < 0 || offset[0] > 9)
					offset[0] = 0;
				if (offset[1] < 0 || offset[1] > 9)
					offset[1] = 0;
				rect.tl.x = x[1] * MNM_PIX_SQR - offset[0] * 0.1 * MNM_PIX_SQR + CURS_OFFSETX * MNM_PIX_SQR;
				if (rect.tl.x < 0)
					rect.tl.x = 0;
				if (rect.tl.x > game->mn_map->width)
					rect.tl.x = game->mn_map->width;
				rect.tl.y = y[1] * MNM_PIX_SQR - offset[1] * 0.1 * MNM_PIX_SQR + CURS_OFFSETY * MNM_PIX_SQR;
				if (rect.tl.y < 0)
					rect.tl.y = 0;
				if (rect.tl.y > game->mn_map->height)
					rect.tl.y = game->mn_map->height;
				rect.br.x = x[1] * MNM_PIX_SQR + MNM_PIX_SQR - offset[0] * 0.1 * MNM_PIX_SQR + CURS_OFFSETX * MNM_PIX_SQR - MNP_GRID;
				if (rect.br.x < 0)
					rect.br.x = 0;
				if (rect.br.x > game->mn_map->width)
					rect.br.x = game->mn_map->width;
				rect.br.y = y[1] * MNM_PIX_SQR + MNM_PIX_SQR - offset[1] * 0.1 * MNM_PIX_SQR + CURS_OFFSETY * MNM_PIX_SQR - MNP_GRID;
				if (rect.br.y < 0)
					rect.br.y = 0;
				if (rect.br.y > game->mn_map->height)
					rect.br.y = game->mn_map->height;
				ft_rectangle(game->mn_map, rect, 0x00FFFFFF);
			}
			x[0]++;
			x[1]++;
		}
		y[0]++;
		y[1]++;
	}
}

t_triangle	ft_set_triangle(t_game *g, int side)
{
	t_triangle	tri;

	if (side == 1)
	{
		tri.a.x = cos(g->player->dir + M_PI_2)
			* CURSOR_COEFA + MNM_PIX_SQR * MNM_DP_SQR_X + MNM_PIX_SQR * 0.5;
		tri.a.y = sin(g->player->dir + M_PI_2)
			* CURSOR_COEFA + MNM_PIX_SQR * MNM_DP_SQR_Y + MNM_PIX_SQR * 0.5;
	}
	else
	{
		tri.a.x = cos(g->player->dir - M_PI_2)
			* CURSOR_COEFA + MNM_PIX_SQR * MNM_DP_SQR_X + MNM_PIX_SQR * 0.5;
		tri.a.y = sin(g->player->dir - M_PI_2)
			* CURSOR_COEFA + MNM_PIX_SQR * MNM_DP_SQR_Y + MNM_PIX_SQR * 0.5;
	}
	tri.b.x = cos(g->player->dir) * CURSOR_COEFB + MNM_PIX_SQR * MNM_DP_SQR_X + MNM_PIX_SQR * 0.5;
	tri.b.y = sin(g->player->dir) * CURSOR_COEFB + MNM_PIX_SQR * MNM_DP_SQR_Y + MNM_PIX_SQR * 0.5;
	tri.c.x = cos(g->player->dir) * CURSOR_COEFC + MNM_PIX_SQR * MNM_DP_SQR_X + MNM_PIX_SQR * 0.5;
	tri.c.y = sin(g->player->dir) * CURSOR_COEFC + MNM_PIX_SQR * MNM_DP_SQR_Y + MNM_PIX_SQR * 0.5;
	return (tri);
}

void	ft_create_mini_map(t_game *g)
{
	t_rectangle	rect;
	t_triangle	tri[2];

	if (!g->mn_map->img)
		g->mn_map->img = mlx_new_image(g->mlx_ptr, g->mn_map->width,
				g->mn_map->height);
	if (!g->mn_map->addr)
		g->mn_map->addr = mlx_get_data_addr(g->mn_map->img, &g->mn_map->b_p_pix,
				&g->mn_map->l_len, &g->mn_map->endian);
	rect.tl.x = 0;
	rect.tl.y = 0;
	rect.br.x = g->mn_map->width;
	rect.br.y = g->mn_map->height;
	ft_rectangle(g->mn_map, rect, 0x00DDDDDD);
	tri[0] = ft_set_triangle(g, 1);
	tri[1] = ft_set_triangle(g, 0);
	ft_mn_map_wall(g);
	ft_put_triangle(g->mn_map, tri[0], 0x00FF0000);
	ft_put_triangle(g->mn_map, tri[1], 0x00FF0000);
	mlx_put_image_to_window(g->mlx_ptr,
		g->mlx_window, g->mn_map->img, g->w_wi - g->mn_map->width - 10, 10);
}
