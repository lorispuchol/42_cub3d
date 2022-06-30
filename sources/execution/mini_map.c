/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:29:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/30 21:21:06 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_set_pix(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->b_p_pix / 8));
	*(unsigned int *)dst = color;
}

void
	ft_wall_boundary_x(t_game *g, int x, t_rectangle *rect)
{
	int	offsetx;

	offsetx = (int)floorf((g->player->x - floorf(g->player->x)) * 10);
	rect->tl.x = x * MNM_PIX_SQR - offsetx
		* 0.1 * MNM_PIX_SQR + CURS_OFFSETX * MNM_PIX_SQR;
	if (rect->tl.x < 0)
		rect->tl.x = 0;
	if (rect->tl.x > g->mn_map->width)
		rect->tl.x = g->mn_map->width;
	rect->br.x = x * MNM_PIX_SQR + MNM_PIX_SQR - offsetx
		* 0.1 * MNM_PIX_SQR + CURS_OFFSETX * MNM_PIX_SQR - MNP_GRID;
	if (rect->br.x < 0)
		rect->br.x = 0;
	if (rect->br.x > g->mn_map->width)
		rect->br.x = g->mn_map->width;
}

void
	ft_wall_boundary_y(t_game *g, int y, t_rectangle *rect)
{
	int	offsety;

	offsety = (int)floorf((g->player->y - floorf(g->player->y)) * 10);
	rect->tl.y = y * MNM_PIX_SQR - offsety
		* 0.1 * MNM_PIX_SQR + CURS_OFFSETX * MNM_PIX_SQR;
	if (rect->tl.y < 0)
		rect->tl.y = 0;
	if (rect->tl.y > g->mn_map->height)
		rect->tl.y = g->mn_map->height;
	rect->br.y = y * MNM_PIX_SQR + MNM_PIX_SQR - offsety
		* 0.1 * MNM_PIX_SQR + CURS_OFFSETX * MNM_PIX_SQR - MNP_GRID;
	if (rect->br.y < 0)
		rect->br.y = 0;
	if (rect->br.y > g->mn_map->height)
		rect->br.y = g->mn_map->height;
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
	ft_init_ray(g);
	mlx_put_image_to_window(g->mlx_ptr,
		g->mlx_window, g->mn_map->img, g->w_wi - g->mn_map->width - 10, 10);
}
