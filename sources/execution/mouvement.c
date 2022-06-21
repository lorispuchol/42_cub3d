/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:13:02 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/21 17:15:30 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_up(t_game *game)
{
	float	tmpx;
	float	tmpy;

	tmpx = game->player->x;
	tmpy = game->player->y;
	game->player->x += cos(game->player->dir) * game->player->speed;
	game->player->y += sin(game->player->dir) * game->player->speed;
	if (game->map[(int)floorf(game->player->y)][(int)floorf(tmpx)] != '0')
		game->player->y = tmpy;
	if (game->map[(int)floorf(tmpy)][(int)floorf(game->player->x)] != '0')
		game->player->y = tmpy;
}

void	ft_down(t_game *game)
{
	float	tmpx;
	float	tmpy;

	tmpx = game->player->x;
	tmpy = game->player->y;
	game->player->x -= cosf(game->player->dir) * game->player->speed;
	game->player->y -= sinf(game->player->dir) * game->player->speed;
	if (game->map[(int)floorf(game->player->y)][(int)floorf(tmpx)] != '0')
		game->player->y = tmpy;
	if (game->map[(int)floorf(tmpy)][(int)floorf(game->player->x)] != '0')
		game->player->y = tmpy;
}

void	ft_right(t_game *game)
{
	float	tmpx;
	float	tmpy;

	tmpx = game->player->x;
	tmpy = game->player->y;
	game->player->x += cosf(game->player->dir - M_PI_2)
		* game->player->speed;
	game->player->y += sinf(game->player->dir - M_PI_2)
		* game->player->speed;
	if (game->map[(int)floorf(game->player->y)][(int)floorf(tmpx)] != '0')
		game->player->y = tmpy;
	if (game->map[(int)floorf(tmpy)][(int)floorf(game->player->x)] != '0')
		game->player->y = tmpy;
}

void	ft_left(t_game *game)
{
	float	tmpx;
	float	tmpy;

	tmpx = game->player->x;
	tmpy = game->player->y;
	game->player->x += cosf(game->player->dir + M_PI_2)
		* game->player->speed;
	game->player->y += sinf(game->player->dir + M_PI_2)
		* game->player->speed;
	if (game->map[(int)floorf(game->player->y)][(int)floorf(tmpx)] != '0')
		game->player->y = tmpy;
	if (game->map[(int)floorf(tmpy)][(int)floorf(game->player->x)] != '0')
		game->player->y = tmpy;
}
