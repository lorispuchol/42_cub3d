/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_loris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:35:34 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/11 04:33:08 by kmammeri         ###   ########lyon.fr   */
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

void
	check_if_wall_ver(int next_grid_ver, float y_ver, t_ray *ray, t_game *game)
{
	if (y_ver < 0 || y_ver > (game->h_map - 1))
	{
		ray->dist_impact_ver = -1;
		ray->if_wall_ver = -1;
		return ;
	}
	if (ray->angle > M_PI_2 && ray->angle < 3 * M_PI_2)
	{
		if (next_grid_ver - 1 < 0 || next_grid_ver - 1 > game->l_map)
		{
			ray->dist_impact_ver = -1;
			ray->if_wall_ver = -1;
			return ;
		}
		if (game->map[(int)floorf(y_ver)][next_grid_ver - 1] == '1')
		{
			fill_ray_ver(ray, game, next_grid_ver, y_ver);
			return ;
		}
	}
	else if ((ray->angle > 0 && ray->angle < M_PI_2)
		|| (ray->angle > 3 * M_PI_2 && ray->angle < 2 * M_PI))
	{
		if (next_grid_ver < 0 || next_grid_ver > game->l_map)
		{
			ray->dist_impact_ver = -1;
			ray->if_wall_ver = -1;
			return ;
		}
		if (game->map[(int)floorf(y_ver)][next_grid_ver] == '1')
		{
			fill_ray_ver(ray, game, next_grid_ver, y_ver);
			return ;
		}
	}
	return ;
}

void
	check_if_wall_hor(int next_grid_hor, float x_hor, t_ray *ray, t_game *game)
{
	if (x_hor < 0 || x_hor > (game->l_map - 1))
	{
		ray->dist_impact_hor = -1;
		ray->if_wall_hor = -1;
		return ;
	}
	if (ray->angle > M_PI && ray->angle < (2 * M_PI))
	{	
		if (next_grid_hor - 1 < 0 || next_grid_hor - 1 > game->h_map)
		{
			ray->dist_impact_hor = -1;
			ray->if_wall_hor = -1;
			return ;
		}
		if (game->map[next_grid_hor - 1][(int)floorf(x_hor)] == '1')
		{
			fill_ray_hor(ray, game, next_grid_hor, x_hor);
			return ;
		}
	}
	else if ((ray->angle > 0 && ray->angle < M_PI))
	{
		if (next_grid_hor < 0 || next_grid_hor > game->h_map)
		{
			ray->dist_impact_hor = -1;
			ray->if_wall_hor = -1;
			return ;
		}
		if (game->map[next_grid_hor][(int)floorf(x_hor)] == '1')
		{
			fill_ray_hor(ray, game, next_grid_hor, x_hor);
			return ;
		}
	}
	return ;
}

void	ft_raycast(t_game *game, t_ray *ray)
{
	if (ray->angle > 2 * M_PI)
		ray->angle -= 2 * M_PI;
	if (ray->angle < 0)
		ray->angle += 2 * M_PI;
	if (ray->angle == 0 || ray->angle == 3 * M_PI_2
		|| ray->angle == M_PI_2 || ray->angle == 2 * M_PI || ray->angle == M_PI)
		ft_angle_particular(game, ray);
	else if (ray->angle > 0 && ray->angle < M_PI_2)
		ft_raycast_btm_rgt(game, ray);
	else if (ray->angle > M_PI_2 && ray->angle < M_PI)
		ft_raycast_btm_lft(game, ray);
	else if (ray->angle > M_PI && ray->angle < 3 * M_PI_2)
		ft_raycast_top_lft(game, ray);
	else if (ray->angle > 3 * M_PI_2 && ray->angle < 2 * M_PI)
		ft_raycast_top_rgt(game, ray);
}

void	ft_reset_rays(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->w_wi)
	{
		game->ray[i].angle = 0;
		game->ray[i].dist_impact_hor = 0;
		game->ray[i].dist_impact_ver = 0;
		game->ray[i].lil_dist = 0;
		game->ray[i].pt_impact_x = 0;
		game->ray[i].pt_impact_y = 0;
		game->ray[i].wall = 0;
		game->ray[i].wall_hor = 0;
		game->ray[i].wall_ver = 0;
		game->ray[i].if_wall_hor = 0;
		game->ray[i].if_wall_ver = 0;
		game->ray[i].next_grid_hor = 0;
		game->ray[i].next_grid_ver = 0;
		game->ray[i].x_hor = 0;
		game->ray[i].y_ver = 0;
	}
}

void	ft_init_ray(t_game *game)
{
	int			i;
	long double	angle;
	int			posx;
	int			posy;

	angle = game->player->dir - game->fov_2;
	i = 0;
	posx = cosf(angle) * 100 + 0.5 * game->mn_map->width;
	posy = sinf(angle) * 100 + 0.5 * game->mn_map->height;
	while (angle < game->player->dir + game->fov_2 && i < game->w_wi)
	{	
		posx = cosf(angle) * 100 + 0.5 * game->mn_map->width;
		posy = sinf(angle) * 100 + 0.5 * game->mn_map->height;
		ft_set_pix(game->mn_map, posx, posy, 0x0000AA00);
		game->ray[i].angle = angle;
		game->ray[i].index = i;
		ft_raycast(game, &game->ray[i]);
		angle += game->angle_rays;
		i++;
	}
}
