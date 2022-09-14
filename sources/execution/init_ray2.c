/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:13:26 by kmammeri          #+#    #+#             */
/*   Updated: 2022/09/14 20:14:11 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_ray2(t_game *g, int i, long double angle)
{
	int	posx;
	int	posy;

	posx = cosf(angle) * g->ray[i].lil_dist
		* MNM_PIX_SQR + 0.5 * g->mn_map->width;
	posy = sinf(angle) * g->ray[i].lil_dist
		* MNM_PIX_SQR + 0.5 * g->mn_map->height;
	if (posx > 10 && posx < g->mn_map->width - 10
		&& posy > 10 && posy < g->mn_map->height - 10)
		ft_set_pix(g->mn_map, posx,
			posy, 0x88FF0000);
}
