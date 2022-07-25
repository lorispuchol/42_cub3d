/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:18:43 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/25 01:09:46 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_rotate_left(t_game *game)
{
	game->player->dir -= game->rot;
	if (game->player->dir > 2 * M_PI)
		game->player->dir -= 2 * M_PI;
	if (game->player->dir < 0)
		game->player->dir += 2 * M_PI;
	if (game->player->dir > M_PI - game->rot && game->player->dir < M_PI
		+ game->rot)
		game->player->dir = M_PI;
	if (game->player->dir > 0 - game->rot && game->player->dir < 0 + game->rot)
		game->player->dir = 0;
	if (game->player->dir > M_PI_2 - game->rot && game->player->dir < M_PI_2
		+ game->rot)
		game->player->dir = M_PI_2;
	if (game->player->dir > 3 * M_PI_2 - game->rot && game->player->dir < 3
		* M_PI_2 + game->rot)
		game->player->dir = 3 * M_PI_2;
}

void	ft_rotate_right(t_game *game)
{
	game->player->dir += game->rot;
	if (game->player->dir > 2 * M_PI)
		game->player->dir -= 2 * M_PI;
	if (game->player->dir < 0)
		game->player->dir += 2 * M_PI;
	if (game->player->dir > M_PI - game->rot && game->player->dir < M_PI
		+ game->rot)
		game->player->dir = M_PI;
	if (game->player->dir > 0 - game->rot && game->player->dir < 0 + game->rot)
		game->player->dir = 0;
	if (game->player->dir > M_PI_2 - game->rot && game->player->dir < M_PI_2
		+ game->rot)
		game->player->dir = M_PI_2;
	if (game->player->dir > 3 * M_PI_2 - game->rot && game->player->dir < 3
		* M_PI_2 + game->rot)
		game->player->dir = 3 * M_PI_2;
}

void	ft_rotate_top(t_game *game)
{
	game->player->tilt += game->rot;
	if (game->player->tilt > M_PI_2 * COEF_TILT_MAX)
		game->player->tilt = M_PI_2 * COEF_TILT_MAX;
}

void	ft_rotate_bot(t_game *game)
{
	game->player->tilt -= game->rot;
	if (game->player->tilt < -M_PI_2 * COEF_TILT_MAX)
		game->player->tilt = -M_PI_2 * COEF_TILT_MAX;
}
