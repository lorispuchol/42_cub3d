/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:57:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/22 18:41:47 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mlx(t_game *g)
{
	g->mlx_ptr = mlx_init();
	g->mlx_window = mlx_new_window(g->mlx_ptr, g->w_wi, g->w_he, "cub3D");
	ft_create_mini_map(g);
	mlx_do_key_autorepeaton(g->mlx_ptr);
	mlx_hook(g->mlx_window, 02, 1L << 0, ft_press_key, g);
	mlx_hook(g->mlx_window, 03, 1L << 1, ft_release_key, g);
	mlx_loop_hook(g->mlx_ptr, ft_action_loop, g);
	mlx_hook(g->mlx_window, 17, 1L << 17, ft_exit_game, g);
	mlx_loop(g->mlx_ptr);
}
