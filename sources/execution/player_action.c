/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:28:19 by kmammeri          #+#    #+#             */
/*   Updated: 2022/09/21 15:43:14 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mouse_directions(t_game *game)
{
	int	x;
	int	y;

	if (game->key->hide_show_mouse == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_move(game->mlx_window, game->w_wi * 0.5, game->w_he * 0.5);
		game->key->hide_show_mouse = 0;
	}
	mlx_mouse_get_pos(game->mlx_window, &x, &y);
	x -= game->w_wi * 0.5;
	y -= game->w_he * 0.5;
	game->player->dir += x * game->rot * game->hori_sensi;
	if (game->player->dir > 2 * M_PI)
		game->player->dir -= 2 * M_PI;
	if (game->player->dir < 0)
		game->player->dir += 2 * M_PI;
	game->player->tilt -= y * game->rot * game->vert_sensi;
	if (game->player->tilt > M_PI_2 * COEF_TILT_MAX)
		game->player->tilt = M_PI_2 * COEF_TILT_MAX;
	if (game->player->tilt < -M_PI_2 * COEF_TILT_MAX)
		game->player->tilt = -M_PI_2 * COEF_TILT_MAX;
	mlx_mouse_move(game->mlx_window, game->w_wi * 0.5, game->w_he * 0.5);
}

int	ft_action_loop(t_game *game, t_rectangle rect)
{
	mlx_clear_window(game->mlx_ptr, game->mlx_window);
	if (game->key->down == 1 && game->key->up != 1)
		ft_down(game);
	if (game->key->rot_bot == 1 && game->key->rot_top != 1)
		ft_rotate_bot(game);
	if (game->key->rot_top == 1 && game->key->rot_bot != 1)
		ft_rotate_top(game);
	if (game->key->up == 1 && game->key->down != 1)
		ft_up(game);
	if (game->key->left == 1 && game->key->right != 1)
		ft_left(game);
	if (game->key->right == 1 && game->key->left != 1)
		ft_right(game);
	if (game->key->rot_left == 1 && game->key->rot_right != 1)
		ft_rotate_left(game);
	if (game->key->rot_right == 1 && game->key->rot_left != 1)
		ft_rotate_right(game);
	ft_create_mini_map(game, rect);
	return (ft_action_loop_2(game));
}

int	ft_press_key_2(int keycode, t_game *g)
{
	if (keycode == 45 && g->key->night_mode == 0)
		g->key->night_mode = 1;
	else if (keycode == 45 && g->key->night_mode == 1)
	{
		if (g->graph->sky->img)
			mlx_destroy_image(g->mlx_ptr, g->graph->sky->img);
		g->graph->sky->img = NULL;
		g->graph->sky->addr = NULL;
		if (g->graph->ground->img)
			mlx_destroy_image(g->mlx_ptr, g->graph->ground->img);
		g->graph->ground->img = NULL;
		g->graph->ground->addr = NULL;
		g->key->night_mode = 0;
		ft_destroy(g);
	}
	ft_press_key_3(g, keycode);
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
	if (keycode == 125)
		game->key->rot_bot = 1;
	if (keycode == 126)
		game->key->rot_top = 1;
	if (keycode == 12 && game->key->lock_mouse != 1)
		game->key->lock_mouse = 1;
	else if (keycode == 12 && game->key->lock_mouse != 0)
		game->key->lock_mouse = 0;
	return (ft_press_key_2(keycode, game));
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
	if (keycode == 125)
		game->key->rot_bot = 0;
	if (keycode == 126)
		game->key->rot_top = 0;
	return (0);
}
