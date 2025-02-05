/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:35:34 by kmammeri          #+#    #+#             */
/*   Updated: 2022/09/14 20:14:04 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_outside_map(t_ray *ray, int cnd)
{
	if (cnd == 0)
	{
		ray->dist_impact_ver = -1;
		ray->if_wall_ver = -1;
	}
	else if (cnd == 1)
	{
		ray->dist_impact_hor = -1;
		ray->if_wall_hor = -1;
	}
}

void
	check_if_wall_ver(int next_grid_ver, float y_ver, t_ray *ray, t_game *game)
{
	if (y_ver < 0 || y_ver > (game->h_map - 1))
		ft_outside_map(ray, 0);
	else if (ray->angle > M_PI_2 && ray->angle < 3 * M_PI_2)
	{
		if (next_grid_ver - 1 < 0 || next_grid_ver - 1 > game->l_map)
		{
			ray->dist_impact_ver = -1;
			ray->if_wall_ver = -1;
		}
		else if (game->map[(int)floorf(y_ver)][next_grid_ver - 1] == '1')
			fill_ray_ver(ray, game, next_grid_ver, y_ver);
	}
	else if ((ray->angle > 0 && ray->angle < M_PI_2)
		|| (ray->angle > 3 * M_PI_2 && ray->angle < 2 * M_PI))
	{
		if (next_grid_ver + 1 < 0 || next_grid_ver + 1 > game->l_map)
		{
			ray->dist_impact_ver = -1;
			ray->if_wall_ver = -1;
		}
		else if (game->map[(int)floorf(y_ver)][next_grid_ver] == '1')
			fill_ray_ver(ray, game, next_grid_ver, y_ver);
	}
}

void
	check_if_wall_hor(int next_grid_hor, float x_hor, t_ray *ray, t_game *game)
{
	if (x_hor < 0 || x_hor > (game->l_map - 1))
		ft_outside_map(ray, 1);
	else if (ray->angle > M_PI && ray->angle < (2 * M_PI))
	{	
		if (next_grid_hor - 1 < 0 || next_grid_hor - 1 > game->h_map)
		{
			ray->dist_impact_hor = -1;
			ray->if_wall_hor = -1;
		}
		else if (game->map[next_grid_hor - 1][(int)floorf(x_hor)] == '1')
			fill_ray_hor(ray, game, next_grid_hor, x_hor);
	}
	else if ((ray->angle > 0 && ray->angle < M_PI))
	{
		if (next_grid_hor + 1 < 0 || next_grid_hor + 1 > game->h_map)
		{
			ray->dist_impact_hor = -1;
			ray->if_wall_hor = -1;
		}
		else if (game->map[next_grid_hor][(int)floorf(x_hor)] == '1')
			fill_ray_hor(ray, game, next_grid_hor, x_hor);
	}
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

void	ft_init_ray(t_game *g)
{
	int			i;
	long double	angle;

	angle = g->player->dir - g->fov_2;
	i = 0;
	while (i < g->w_wi)
	{	
		g->ray[i].angle = angle;
		g->ray[i].index = i;
		ft_raycast(g, &g->ray[i]);
		if (g->key->mn_map == 1 && SHOW_IMPACT_MN_MAP)
			ft_init_ray2(g, i, angle);
		if (i <= g->w_wi * 0.5)
			angle = g->player->dir - atanf((fabs(g->w_wi * 0.5 - i)) / g->r_v);
		else if (i > g->w_wi * 0.5)
			angle = g->player->dir + atanf((fabs(g->w_wi * 0.5 - i)) / g->r_v);
		i++;
	}
}
