/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:12:42 by kmammeri          #+#    #+#             */
/*   Updated: 2022/09/14 18:04:06 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_increment_both(int *i, int *j)
{
	*i += 1;
	*j += 1;
}

void	ft_innit_param(t_game *g, int *i, int *j, int dp_sqr)
{
	if (dp_sqr == MNM_DP_SQR_Y)
		*i = (int)g->player->y - dp_sqr;
	if (dp_sqr == MNM_DP_SQR_X)
		*i = (int)g->player->x - dp_sqr;
	*j = 0;
}

void	ft_cnd_wall(t_game	*g, int x[2], int y[2])
{
	t_rectangle	rect;

	if (g->map[y[0]][x[0]] == '1' && g->map[y[0]][x[0]])
	{
		ft_wall_boundary_x(g, x[1], &rect);
		ft_wall_boundary_y(g, y[1], &rect);
		ft_rectangle(g->mn_map, rect, 0x33AAAAAA);
	}
	if (g->map[y[0]][x[0]] == '0')
	{
		ft_wall_boundary_x(g, x[1], &rect);
		ft_wall_boundary_y(g, y[1], &rect);
		ft_rectangle(g->mn_map, rect, 0x33FFFFFF);
	}
}

void	ft_mn_map_wall(t_game *g)
{
	int			x[2];
	int			y[2];

	ft_innit_param(g, &y[0], &y[1], MNM_DP_SQR_Y);
	while (y[0] < 0)
		ft_increment_both(&y[0], &y[1]);
	while (g->map[y[0]] && y[0] - 1 <= (int)roundf(g->player->y) + MNM_DP_SQR_Y
		&& y[1] * MNM_PIX_SQR <= g->mn_map->height - MNM_PIX_SQR)
	{
		ft_innit_param(g, &x[0], &x[1], MNM_DP_SQR_X);
		while (x[0] < 0)
			ft_increment_both(&x[0], &x[1]);
		while (g->map[y[0]][x[0]] && x[0] <= (int)roundf(g->player->x)
			+ MNM_DP_SQR_X && x[1]
			* MNM_PIX_SQR <= g->mn_map->width - MNM_PIX_SQR)
		{
			ft_cnd_wall(g, x, y);
			ft_increment_both(&x[0], &x[1]);
		}
		ft_increment_both(&y[0], &y[1]);
	}
}

t_triangle	ft_set_triangle(t_game *g, int side)
{
	t_triangle	tri;

	if (side == 1)
	{
		tri.a.x = cos(g->player->dir + M_PI_2)
			* CURSOR_COEFA + g->mn_map->width * 0.5;
		tri.a.y = sin(g->player->dir + M_PI_2)
			* CURSOR_COEFA + g->mn_map->height * 0.5;
	}
	else
	{
		tri.a.x = cos(g->player->dir - M_PI_2)
			* CURSOR_COEFA + g->mn_map->width * 0.5;
		tri.a.y = sin(g->player->dir - M_PI_2)
			* CURSOR_COEFA + g->mn_map->height * 0.5;
	}
	tri.b.x = cos(g->player->dir) * CURSOR_COEFB
		+ g->mn_map->width * 0.5;
	tri.b.y = sin(g->player->dir) * CURSOR_COEFB
		+ g->mn_map->height * 0.5;
	tri.c.x = cos(g->player->dir) * CURSOR_COEFC
		+ g->mn_map->width * 0.5;
	tri.c.y = sin(g->player->dir) * CURSOR_COEFC
		+ g->mn_map->height * 0.5;
	return (tri);
}
