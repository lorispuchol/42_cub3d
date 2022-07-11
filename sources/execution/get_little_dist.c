/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_little_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:10:43 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/11 23:16:31 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_ray_ver(t_ray *ray, t_game *game, int next_grid_ver, float y_ver)
{
	ray->dist_impact_ver = sqrt(powf(game->player->x - next_grid_ver, 2)
			+ powf(game->player->y - y_ver, 2));
	ray->if_wall_ver = 1;
	if (ray->angle > M_PI_2 && ray->angle < M_PI_2 * 3)
		ray->wall_ver = SP_EAST;
	else if ((ray->angle > 0 && ray->angle < M_PI_2)
		|| (ray->angle > 3 * M_PI_2 && ray->angle < 2 * M_PI))
		ray->wall_ver = SP_WEST;
}

void	fill_ray_hor(t_ray *ray, t_game *game, int next_grid_hor, float x_hor)
{
	ray->dist_impact_hor = sqrt(powf(game->player->y - next_grid_hor, 2)
			+ powf(game->player->x - x_hor, 2));
	ray->if_wall_hor = 1;
	if (ray->angle > M_PI && ray->angle < M_PI * 2)
		ray->wall_hor = SP_SOUTH;
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->wall_hor = SP_NORTH;
}

void	get_lil_dist_2(t_ray *ray)
{
	if (ray->dist_impact_hor <= ray->dist_impact_ver)
	{
		ray->lil_dist = ray->dist_impact_hor;
		ray->pt_impact_x = ray->x_hor;
		ray->pt_impact_y = ray->next_grid_hor;
		ray->wall = ray->wall_hor;
	}
	else if (ray->dist_impact_ver < ray->dist_impact_hor)
	{
		ray->lil_dist = ray->dist_impact_ver;
		ray->pt_impact_x = ray->next_grid_ver;
		ray->pt_impact_y = ray->y_ver;
		ray->wall = ray->wall_ver;
	}
	else
	{
		ray->lil_dist = -2;
		ray->pt_impact_x = -2;
		ray->pt_impact_y = -2;
		ray->wall = -2;
	}
}

void	get_lil_dist(t_ray *ray)
{
	if (ray->dist_impact_hor < 0)
	{
		ray->lil_dist = ray->dist_impact_ver;
		ray->pt_impact_x = ray->next_grid_ver;
		ray->pt_impact_y = ray->y_ver;
		ray->wall = ray->wall_ver;
		return ;
	}
	if (ray->dist_impact_ver < 0)
	{
		ray->lil_dist = ray->dist_impact_hor;
		ray->pt_impact_x = ray->x_hor;
		ray->pt_impact_y = ray->next_grid_hor;
		ray->wall = ray->wall_hor;
		return ;
	}
	get_lil_dist_2(ray);
}
