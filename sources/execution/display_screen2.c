/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_screen2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:02:55 by kmammeri          #+#    #+#             */
/*   Updated: 2022/09/21 15:27:06 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void
	ft_floor2(t_game *g, long double fr_xy[2], long double stp_xy[2], int xy[3])
{
	int	cell_xy[2];
	int	t_xy[2];

	while (xy[0] < g->w_wi)
	{
		cell_xy[0] = (int)fr_xy[0];
		cell_xy[1] = (int)fr_xy[1];
		t_xy[0] = (int)(g->graph->ground->width
				* (fr_xy[0] - cell_xy[0]));
		t_xy[1] = (int)(g->graph->ground->height
				* (fr_xy[1] - cell_xy[1]));
		while (t_xy[1] >= g->graph->ground->height)
			t_xy[1] -= g->graph->ground->height;
		while (t_xy[1] < 0)
			t_xy[1] += g->graph->ground->height;
		while (t_xy[0] >= g->graph->ground->width)
			t_xy[0] -= g->graph->ground->width;
		while (t_xy[0] < 0)
			t_xy[0] += g->graph->ground->width;
		fr_xy[0] += stp_xy[0];
		fr_xy[1] += stp_xy[1];
		ft_set_pix(g->screen, xy[0], xy[2],
			ft_get_color(g->graph->ground, t_xy[0], t_xy[1]));
		xy[0]++;
	}
}

void	floor1(t_game *g, int xy[3], long double raydir_xy0[4])
{
	if (!g->graph->ground->img)
		g->graph->ground->img = mlx_xpm_file_to_image(g->mlx_ptr,
				"./sprites/stone_floor.xpm", &g->graph->ground->width,
				&g->graph->ground->height);
	if (!g->graph->ground->addr)
		g->graph->ground->addr = mlx_get_data_addr(g->graph->ground->img,
				&g->graph->ground->b_p_pix, &g->graph->ground->l_len,
				&g->graph->ground->endian);
	xy[0] = 0;
	xy[1] = g->w_he * 0.5 + 1;
	xy[2] = g->w_he * 0.5 + (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	raydir_xy0[0] = cosf(g->player->dir) - cosf(g->player->dir + M_PI_2) * 0.65;
	raydir_xy0[1] = sinf(g->player->dir) - sinf(g->player->dir + M_PI_2) * 0.65;
	raydir_xy0[2] = cosf(g->player->dir) + cosf(g->player->dir + M_PI_2) * 0.65;
	raydir_xy0[3] = sinf(g->player->dir) + sinf(g->player->dir + M_PI_2) * 0.65;
}

void	ft_night1(t_game *g)
{
	if (!g->graph->sky->img)
		g->graph->sky->img = mlx_xpm_file_to_image(g->mlx_ptr,
				"./sprites/full_sun.xpm", &g->graph->sky->width,
				&g->graph->sky->height);
	if (!g->graph->sky->addr)
		g->graph->sky->addr = mlx_get_data_addr(g->graph->sky->img,
				&g->graph->sky->b_p_pix, &g->graph->sky->l_len,
				&g->graph->sky->endian);
}
