/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:59:17 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/01 23:41:55 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

void	ft_display_screen(t_game *g)
{	
	int			i;
	t_rectangle	back;

	if (!g->screen->img)
		g->screen->img = mlx_new_image(g->mlx_ptr, g->w_wi, g->w_he);
	if (!g->screen->addr)
		g->screen->addr = mlx_get_data_addr(g->screen->img,
				&g->screen->b_p_pix, &g->screen->l_len, &g->screen->endian);
	i = 0;
	back.tl.x = 0;
	back.tl.y = 0;
	back.br.x = g->w_wi;
	back.br.y = g->w_he * 0.5 - 1;
	ft_rectangle(g->screen, back, g->graph->ceiling);
	back.tl.x = 0;
	back.tl.y = g->w_he * 0.5;
	back.br.x = g->w_wi;
	back.br.y = g->w_he - 2;
	ft_rectangle(g->screen, back, g->graph->floor);
	ft_cast_ray(g);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->screen->img, 0, 0);
}