/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:11:36 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/07/08 19:56:33 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_sprite_ray(t_game *game, int x, int height_wall, t_data *sprite)
{
	int	y[2];
	int color_x;
	int	color_y;
	int true_y;

	y[0] = game->w_he * 0.5 - height_wall * 0.5;
	true_y = 0;
	if (y[0] < 0)
		y[0] = 0;
	y[1] = game->w_he * 0.5 + height_wall * 0.5;
	if (y[1] > game->w_he)
		y[1] = game->w_he - 1;
	if (height_wall > game->screen->height)
		true_y = height_wall * 0.5 - game->screen->height * 0.5 ;
	while (y[0] < y[1])
	{
		color_x = (int)((game->ray[x].pt_impact_x - floorf(game->ray[x].pt_impact_x) + game->ray[x].pt_impact_y - floorf(game->ray[x].pt_impact_y)) * sprite->width);
		if (true_y < game->screen->height / 2)
			color_y = (int)(((float)true_y / (float)height_wall) * sprite->height);
		else
			color_y = (int)(((float)true_y / (float)height_wall) * sprite->height);
		// if (color_y >= sprite->height)
		// 	color_y = sprite->height - 1;
		// if (color_y < 0)
		// 	color_y = 0;
		// if (color_x >= sprite->width)
		// 	color_x = sprite->width - 1;
		// if (color_x < 0)
		// 	color_x = 0;
		// printf("x color == %d y color == %d\n", color_x, color_y);
		ft_set_pix(game->screen, x, y[0], ft_get_color(sprite, color_x, color_y));
		y[0]++;
		true_y++;
	}
}

void	ft_print_ray(t_game *game)
{
	float		good_dist;
	int			height_wall;
	int			i;
	// t_rectangle rect;

	i = -1;
	while (++i < game->w_wi)
	{
		good_dist = cosf(fabs((double)game->ray[i].angle - (double)game->player->dir)) * game->ray[i].lil_dist;
		height_wall = (int)((float)game->w_he / good_dist);
		// rect.tl.x = i;
		// rect.tl.y = game->w_he * 0.5 - height_wall * 0.5;
		// if (rect.tl.y < 0)
		// 	rect.tl.y = 0;
		// rect.br.x = i;
		// rect.br.y = game->w_he * 0.5 + height_wall * 0.5;
		// if (rect.br.y > game->w_he)
		// 	rect.br.y = game->w_he - 1;
		// if (game->ray[i].wall == SP_EAST)
		// 	ft_rectangle(game->screen, rect, 0x00FFFFFF);
		// if (game->ray[i].wall == SP_NORTH)
		// 	ft_rectangle(game->screen, rect, 0x00DDDDDD);
		// if (game->ray[i].wall == SP_SOUTH)
		// 	ft_rectangle(game->screen, rect, 0x00BBBBBB);
		// if (game->ray[i].wall == SP_WEST)
		// 	ft_rectangle(game->screen, rect, 0x00999999);

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