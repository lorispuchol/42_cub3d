/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:28:19 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/21 16:39:04 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_rotate_left(t_game *game)
{
	game->player->dir -= game->rot;
	if (game->player->dir > 2 * M_PI)
		game->player->dir -= 2 * M_PI;
	if (game->player->dir < -M_PI)
		game->player->dir += 2 * M_PI;
}

void	ft_rotate_right(t_game *game)
{
	game->player->dir += game->rot;
	if (game->player->dir > 2 * M_PI)
		game->player->dir -= 2 * M_PI;
	if (game->player->dir < -M_PI)
		game->player->dir += 2 * M_PI;
}

int	ft_press_key(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit_game(game);
	if (keycode == 13)
		ft_up(game);
	if (keycode == 1)
		ft_down(game);
	if (keycode == 2)
		ft_right(game);
	if (keycode == 0)
		ft_left(game);
	if (keycode == 123)
		ft_rotate_left(game);
	if (keycode == 124)
		ft_rotate_right(game);
	ft_create_mini_map(game);
	return (0);
}
