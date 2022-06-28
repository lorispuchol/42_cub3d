/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:28:19 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/23 22:39:31 by kmammeri         ###   ########lyon.fr   */
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

int	ft_action_loop(t_game *game)
{
	// dprintf(1, "up == %d\ndown == %d\nleft == %d\nright == %d\nrot left == %d\nrot right == %d\n", game->key->up, game->key->down, game->key->left, game->key->right, game->key->rot_left, game->key->rot_right);
	if (game->key->down == 1 && game->key->up != 1)
		ft_down(game);
	if (game->key->up == 1 && game->key->down != 1)
		ft_up(game);
	if (game->key->left == 1 && game->key->right != 1)
		ft_left(game);
	if (game->key->right == 1 && game->key->left != 1)
		ft_right(game);
	if (game->key->rot_left == 1  && game->key->rot_right != 1)
		ft_rotate_left(game);
	if (game->key->rot_right == 1 && game->key->rot_left != 1)
		ft_rotate_right(game);
	// if (game->key->down == 1 || game->key->up == 1 || game->key->left == 1
	// 	|| game->key->right == 1 || game->key->rot_right == 1
	// 	|| game->key->rot_left == 1)
	ft_create_mini_map(game);
	return (0);
}

int	ft_press_key(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit_game(game);
	if (keycode == 13)
		game->key->up = 1;
	if (keycode == 1)
		game->key->down = 1;
	if (keycode == 2)
		game->key->right = 1;
	if (keycode == 0)
		game->key->left = 1;
	if (keycode == 123)
		game->key->rot_left = 1;
	if (keycode == 124)
		game->key->rot_right = 1;
	return (0);
}

int	ft_release_key(int keycode, t_game *game)
{
	if (keycode == 13)
		game->key->up = 0;
	if (keycode == 1)
		game->key->down = 0;
	if (keycode == 2)
		game->key->right = 0;
	if (keycode == 0)
		game->key->left = 0;
	if (keycode == 123)
		game->key->rot_left = 0;
	if (keycode == 124)
		game->key->rot_right = 0;
	return (0);
}