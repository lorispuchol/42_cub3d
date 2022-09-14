/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:39:43 by lpuchol           #+#    #+#             */
/*   Updated: 2022/09/14 20:12:04 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_action_loop_2(t_game *game)
{
	if (game->key->lock_mouse == 1)
	{
		if (game->key->hide_show_mouse == 0)
			game->key->hide_show_mouse = mlx_mouse_show() * 0 + 1;
	}
	else if (game->key->lock_mouse == 0)
		ft_mouse_directions(game);
	return (0);
}
