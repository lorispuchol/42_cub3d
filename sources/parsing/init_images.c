/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:16:56 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/26 02:34:41 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mn_map(t_game *game)
{
	game->mn_map = ft_xmalloc(sizeof(t_data));
	game->mn_map->img = NULL;
	game->mn_map->addr = NULL;
	game->mn_map->b_p_pix = 0;
	game->mn_map->l_len = 0;
	game->mn_map->endian = 0;
	game->mn_map->height = MNM_PIX_SQR
		* (MNM_DP_SQR_Y * 2 + game->w_he / HEIGHT);
	game->mn_map->width = MNM_PIX_SQR * (MNM_DP_SQR_X * 2 + game->w_wi / WIDTH);
}

void	ft_init_screen(t_game *game)
{
	game->screen = ft_xmalloc(sizeof(t_data));
	game->screen->img = NULL;
	game->screen->addr = NULL;
	game->screen->b_p_pix = 0;
	game->screen->l_len = 0;
	game->screen->endian = 0;
	game->screen->height = game->w_he;
	game->screen->width = game->w_wi;
}
