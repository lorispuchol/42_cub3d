/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:11:36 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/07/08 14:23:24 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_ray(t_game *game)
{
	float		good_dist;
	int			height_wall;
	int			i;
	t_rectangle rect;

	i = -1;
	while (++i < game->w_wi)
	{
		good_dist = cosf(fabs((double)game->ray[i].angle - (double)game->player->dir)) * game->ray[i].lil_dist;
		height_wall = (int)((float)game->w_he / good_dist);
		rect.tl.x = i;
		rect.tl.y = game->w_he * 0.5 - height_wall * 0.5;
		if (rect.tl.y < 0)
			rect.tl.y = 0;
		rect.br.x = i;
		rect.br.y = game->w_he * 0.5 + height_wall * 0.5;
		if (rect.br.y > game->w_he)
			rect.br.y = game->w_he - 1;
		if (game->ray[i].wall == SP_EAST)
			ft_rectangle(game->screen, rect, 0x00FFFFFF);
		if (game->ray[i].wall == SP_NORTH)
			ft_rectangle(game->screen, rect, 0x00DDDDDD);
		if (game->ray[i].wall == SP_SOUTH)
			ft_rectangle(game->screen, rect, 0x00BBBBBB);
		if (game->ray[i].wall == SP_WEST)
			ft_rectangle(game->screen, rect, 0x00999999);
	}
}