/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:11:36 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/07/26 04:11:02 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>
#include <stdio.h>

int	x_col(t_game *g, int x, t_data *sprite)
{
	int	color_x;

	color_x = (int)((g->ray[x].pt_impact_x
				- floorf(g->ray[x].pt_impact_x)
				+ g->ray[x].pt_impact_y
				- floorf(g->ray[x].pt_impact_y)) * sprite->width);
	return (color_x);
}

int	fogged_color(t_game *g, int color, int height_wall)
{
	int		trgb[4];
	float	fog;

	if (g->key->night_mode == 1)
	{
		trgb[0] = get_t(color);
		fog = (float)(-height_wall * 70 + g->w_he * 2) / (float)(g->w_he) + 0.6;
		if (fog > 1)
			fog = 1;
		if (fog < 0)
			fog = 0;
		trgb[1] = (1 - fog) * get_r(color) + fog * 25;
		trgb[2] = (1 - fog) * get_g(color) + fog * 25;
		trgb[3] = (1 - fog) * get_b(color) + fog * 25;
	}
	else
		return (color);
	return (create_trgb(trgb[0], trgb[1], trgb[2], trgb[3]));
}

void	print_sprite_ray(t_game *g, int x, int height_wall, t_data *sp)
{
	int	y[2];
	int	ycol;
	int	true_y;

	y[0] = g->w_he * 0.5 - height_wall * 0.5
		+ (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	true_y = 0;
	if (y[0] < 0)
		y[0] = 0;
	y[1] = g->w_he * 0.5 + height_wall * 0.5
		+ (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	if (y[1] > g->w_he)
		y[1] = g->w_he;
	if (height_wall > g->screen->height
		+ (int)(sinf(g->player->tilt) * g->w_he))
		true_y = height_wall * 0.5 - g->screen->height
			* 0.5 - (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	while (y[0] < y[1])
	{
		ycol = (int)(((float)true_y / (float)height_wall) * sp->height);
		ft_set_pix(g->screen, x, y[0], fogged_color(g, ft_get_color(sp, x_col(g, x, sp), ycol), height_wall));
		y[0]++;
		true_y++;
	}
}

void	ft_print_ray(t_game *game)
{
	float		good_dist;
	int			height_wall;
	int			i;

	i = -1;
	while (++i < game->w_wi)
	{
		good_dist = cosf(fabsl((double)game->ray[i].angle
					- (double)game->player->dir)) * game->ray[i].lil_dist;
		height_wall = (int)((float)game->w_he / (good_dist));
		if (game->ray[i].wall == SP_EAST)
			print_sprite_ray(game, i, height_wall, game->graph->sp_ea);
		if (game->ray[i].wall == SP_NORTH)
			print_sprite_ray(game, i, height_wall, game->graph->sp_no);
		if (game->ray[i].wall == SP_SOUTH)
			print_sprite_ray(game, i, height_wall, game->graph->sp_so);
		if (game->ray[i].wall == SP_WEST)
			print_sprite_ray(game, i, height_wall, game->graph->sp_we);
	}
}
