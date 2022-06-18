/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:57:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/18 16:27:46 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mlx(t_game *g)
{
	g->mlx_ptr = mlx_init();
	g->mlx_window = mlx_new_window(g->mlx_ptr, g->w_wi, g->w_he, "cub3D");
	ft_create_mini_map(g);
	mlx_hook(g->mlx_window, 17, 1L << 17, ft_exit_game, g);
	mlx_loop(g->mlx_ptr);
}
