/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:11:36 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/07/12 02:57:36 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	x_col(t_game *g, int x, t_data *sprite)
{
	int	color_x;

	color_x = (int)((g->ray[x].pt_impact_x
				- floorf(g->ray[x].pt_impact_x)
				+ g->ray[x].pt_impact_y
				- floorf(g->ray[x].pt_impact_y)) * sprite->width);
	return (color_x);
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
		y[1] = g->w_he - 1;
	if (height_wall > g->screen->height
		+ (int)(sinf(g->player->tilt) * g->w_he))
		true_y = height_wall * 0.5 - g->screen->height
			* 0.5 - (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	while (y[0] < y[1])
	{
		ycol = (int)(((float)true_y / (float)height_wall) * sp->height);
		ft_set_pix(g->screen, x, y[0], ft_get_color(sp, x_col(g, x, sp), ycol));
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
		good_dist = cosf(fabs((double)game->ray[i].angle
					- (double)game->player->dir)) * game->ray[i].lil_dist;
		height_wall = (int)((float)game->w_he / good_dist);
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
