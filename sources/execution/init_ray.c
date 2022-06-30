/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:35:34 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/30 21:30:12 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_coef_dir(t_game *game, int i, float angle)
{
	int	posx;
	int	posy;

	i++;
	posx = game->player->x + cosf(angle);
	posy = game->player->y + sinf(angle);
	game->ray[i].cdirx = (posy - game->player->y) / (posx - game->player->y);
}

void	ft_init_ray(t_game *game)
{
	int		i;
	float	angle;
	int		posx;
	int		posy;

	angle = game->player->dir - game->fov_2;
	i = 0;
	posx = cosf(angle) * 100 + 0.5 * game->mn_map->width;
	posy = sinf(angle) * 100 + 0.5 * game->mn_map->height;
	while (angle < game->player->dir + game->fov_2 && i < game->w_wi)
	{
		posx = cosf(angle) * 100 + 0.5 * game->mn_map->width;
		posy = sinf(angle) * 100 + 0.5 * game->mn_map->height;
		ft_set_pix(game->mn_map, posx, posy, 0x0000AA00);
		// ft_get_coef_dir(game, i, angle);
		angle += game->r_h;
		i++;
	}
}
