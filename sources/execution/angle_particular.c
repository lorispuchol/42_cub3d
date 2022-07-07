/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_particular.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:18:23 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/07/07 17:53:59 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ray_right(t_ray *ray, t_game *game)
{
	int	x;

	ray->pt_impact_y = game->player->y;
	x = (int)floorf(game->player->x) + 1;
	while (game->map[(int)floorf(ray->pt_impact_y)][x] != '1')
		x++;
	ray->pt_impact_x = x;
	ray->wall = SP_WEST;
	ray->lil_dist = fabsf(ray->pt_impact_x - game->player->x);
}

void	ft_ray_left(t_ray *ray, t_game *game)
{
	int	x;

	ray->pt_impact_y = game->player->y;
	x = (int)floorf(game->player->x);
	while (game->map[(int)floorf(ray->pt_impact_y)][x - 1] != '1')
		x--;
	ray->pt_impact_x = x;
	ray->wall = SP_EAST;
	ray->lil_dist = fabsf(ray->pt_impact_x - game->player->x);
}

void	ft_ray_top(t_ray *ray, t_game *game)
{
	int	y;

	ray->pt_impact_x = game->player->x;
	y = (int)floorf(game->player->y);
	while (game->map[y - 1][(int)floorf(ray->pt_impact_x)] != '1')
		y--;
	ray->pt_impact_y = y;
	ray->wall = SP_SOUTH;
	ray->lil_dist = fabsf(ray->pt_impact_y - game->player->y);
}

void	ft_ray_bot(t_ray *ray, t_game *game)
{
	int	y;

	ray->pt_impact_x = game->player->x;
	y = (int)floorf(game->player->y) + 1;
	while (game->map[y][(int)floorf(ray->pt_impact_x)] != '1')
		y++;
	ray->pt_impact_y = y;
	ray->wall = SP_NORTH;
	ray->lil_dist = fabsf(ray->pt_impact_y - game->player->y);
}

void ft_angle_particular(t_game *game, t_ray *ray)
{
	if (ray->angle == 0 || ray->angle ==  2 * M_PI)
		ft_ray_right(ray, game);
	else if (ray->angle == M_PI)
		ft_ray_left(ray, game);
	else if (ray->angle == M_PI_2)
		ft_ray_bot(ray, game);
	else if (ray->angle == 3 * M_PI_2)
		ft_ray_top(ray, game);
}