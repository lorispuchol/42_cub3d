/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_loris                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:35:34 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/03 23:00:55 by lpuchol          ###   ########.fr       */
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

int	check_if_wall_ver(int next_grid_ver, int first_cross_ver, float angle, t_game *game)
{
	if (first_cross_ver < 0 || first_cross_ver > (game->h_map - 1))
		return (0);
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
	{	
		if (game->map[(int)floorf(first_cross_ver)][next_grid_ver - 1] == '1')	
			return (1);
	}
	else if ((angle > 0 && angle < M_PI_2) || (angle > 3 * M_PI_2 && angle < 2 * M_PI))
	{
		if (game->map[(int)floorf(first_cross_ver)][next_grid_ver] == '1')
			return (1);
	}
	return (0);
}

int	check_if_wall_hor(int next_grid_hor, int first_cross_hor, float angle, t_game *game)
{
	if (first_cross_hor < 0 || first_cross_hor > (game->l_map - 1))
		return (0);
	if (angle > M_PI && angle < (2 * M_PI))
	{	
		if (game->map[next_grid_hor - 1][(int)floorf(first_cross_hor)] == '1')	
			return (1);
	}
	else if ((angle > 0 && angle < M_PI))
	{
		if (game->map[next_grid_hor][(int)floorf(first_cross_hor)] == '1')
			return (1);
	}
	return (0);
}

void ft_get_first_grid(t_game *game/*, float angle*/)
{
	int next_grid_hor;
	int next_grid_ver;
	float first_cross_hor;
	float first_cross_ver;

	if (game->player->dir == 0 || game->player->dir == 3 * M_PI_2 || game->player->dir == M_PI_2 || game->player->dir == 2 * M_PI || game->player->dir == M_PI || game->player->dir == -M_PI_2)
	{
		dprintf(1, "dir on axe\n");
		return ;
	}
	next_grid_ver = 0;
	next_grid_hor = 0;
	if (game->player->dir > M_PI && game->player->dir < (2 * M_PI))
		next_grid_hor = (int)floorf(game->player->y);
	else if (game->player->dir > 0 && game->player->dir < M_PI)
		next_grid_hor = (int)floorf(game->player->y) + 1;
	if (game->player->dir > M_PI_2 && game->player->dir < (3 * M_PI_2))
		next_grid_ver = (int)floorf(game->player->x);
	else if ((game->player->dir >= 0 && game->player->dir < M_PI_2) || (game->player->dir > (3 * M_PI_2) && game->player->dir <= (2 * M_PI)))
		next_grid_ver = (int)floorf(game->player->x) + 1;
	first_cross_ver = ((float)next_grid_ver - game->player->x) * tan((double)game->player->dir) + game->player->y;
	if (game->player->dir > M_PI && game->player->dir < 2 * M_PI)
		first_cross_hor = fabsf((float)next_grid_hor - game->player->y) * tan((double)game->player->dir + M_PI_2) + game->player->x;
	else if (game->player->dir > 0 && game->player->dir < M_PI)
		first_cross_hor = fabsf((float)next_grid_hor - game->player->y) * tan(M_PI_2 - (double)game->player->dir) + game->player->x;
	else
		first_cross_hor = 0;
	
	dprintf(1, "ver wall : %d  ",  check_if_wall_ver(next_grid_ver, first_cross_ver, game->player->dir, game));
	dprintf(1, "hor wall : %d\n",  check_if_wall_hor(next_grid_hor, first_cross_hor, game->player->dir, game));
	ft_set_pix(game->mn_map, game->mn_map->width * 0.5 + 10, game->mn_map->height * 0.5 + 10, 0x000000FF);
	// dprintf(1,"pix posi: %d\n", (int)floorf((next_grid_ver - game->player->x)));
	ft_set_pix(game->mn_map, game->mn_map->width * 0.5 + (int)floorf((next_grid_ver - game->player->x)), game->mn_map->height * 0.5 + (int)floorf((first_cross_ver - game->player->x)), 0x0000FF00);
	// dprintf(1, "premier croisement ver: x=%d y=%f  ---  premier croisement hor: x=%f y=%d  ---  posi x: %f  posi y: %f  dir: %Lf\n", next_grid_ver, first_cross_ver, first_cross_hor, next_grid_hor, game->player->x, game->player->y, game->player->dir);
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
		ft_get_first_grid(game/*, angle*/);
		angle += game->r_h;
		i++;
	}
}
