/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:16:59 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/07/11 23:28:47 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_raycast_btm_rgt(t_game *g, t_ray *ray)
{
	ray->next_grid_hor = (int)floorf(g->player->y) + 1;
	ray->next_grid_ver = (int)floorf(g->player->x) + 1;
	while (ray->if_wall_ver == 0 || ray->if_wall_hor == 0)
	{
		if (ray->if_wall_ver == 0)
		{
			ray->y_ver = ((float)ray->next_grid_ver - g->player->x)
				* tan((double)ray->angle) + g->player->y;
			check_if_wall_ver(ray->next_grid_ver, ray->y_ver, ray, g);
			if (ray->if_wall_ver == 0)
				ray->next_grid_ver++;
		}
		if (ray->if_wall_hor == 0)
		{
			ray->x_hor = fabsf((float)ray->next_grid_hor - g->player->y)
				* tan(M_PI_2 - (double)ray->angle) + g->player->x;
			check_if_wall_hor(ray->next_grid_hor, ray->x_hor, ray, g);
			if (ray->if_wall_hor == 0)
				ray->next_grid_hor++;
		}
	}
	get_lil_dist(ray);
}

void	ft_raycast_btm_lft(t_game *g, t_ray *ray)
{
	ray->next_grid_hor = (int)floorf(g->player->y) + 1;
	ray->next_grid_ver = (int)floorf(g->player->x);
	while (ray->if_wall_ver == 0 || ray->if_wall_hor == 0)
	{
		if (ray->if_wall_ver == 0)
		{
			ray->y_ver = ((float)ray->next_grid_ver - g->player->x)
				* tan((double)ray->angle) + g->player->y;
			check_if_wall_ver(ray->next_grid_ver, ray->y_ver, ray, g);
			if (ray->if_wall_ver == 0)
				ray->next_grid_ver--;
		}
		if (ray->if_wall_hor == 0)
		{
			ray->x_hor = fabsf((float)ray->next_grid_hor - g->player->y)
				* tan(M_PI_2 - (double)ray->angle) + g->player->x;
			check_if_wall_hor(ray->next_grid_hor, ray->x_hor, ray, g);
			if (ray->if_wall_hor == 0)
				ray->next_grid_hor++;
		}
	}
	get_lil_dist(ray);
}

void	ft_raycast_top_lft(t_game *g, t_ray *ray)
{
	ray->next_grid_hor = (int)floorf(g->player->y);
	ray->next_grid_ver = (int)floorf(g->player->x);
	while (ray->if_wall_ver == 0 || ray->if_wall_hor == 0)
	{
		if (ray->if_wall_ver == 0)
		{
			ray->y_ver = ((float)ray->next_grid_ver - g->player->x)
				* tan((double)ray->angle) + g->player->y;
			check_if_wall_ver(ray->next_grid_ver, ray->y_ver, ray, g);
			if (ray->if_wall_ver == 0)
				ray->next_grid_ver--;
		}
		if (ray->if_wall_hor == 0)
		{
			ray->x_hor = fabsf((float)ray->next_grid_hor - g->player->y)
				* tan((double)ray->angle + M_PI_2) + g->player->x;
			check_if_wall_hor(ray->next_grid_hor, ray->x_hor, ray, g);
			if (ray->if_wall_hor == 0)
				ray->next_grid_hor--;
		}
	}
	get_lil_dist(ray);
}

void	ft_raycast_top_rgt(t_game *g, t_ray *ray)
{	
	ray->next_grid_hor = (int)floorf(g->player->y);
	ray->next_grid_ver = (int)floorf(g->player->x) + 1;
	while (ray->if_wall_ver == 0 || ray->if_wall_hor == 0)
	{
		if (ray->if_wall_ver == 0)
		{
			ray->y_ver = ((float)ray->next_grid_ver - g->player->x)
				* tan((double)ray->angle) + g->player->y;
			check_if_wall_ver(ray->next_grid_ver, ray->y_ver, ray, g);
			if (ray->if_wall_ver == 0)
				ray->next_grid_ver++;
		}
		if (ray->if_wall_hor == 0)
		{
			ray->x_hor = fabsf((float)ray->next_grid_hor - g->player->y)
				* tan((double)ray->angle + M_PI_2) + g->player->x;
			check_if_wall_hor(ray->next_grid_hor, ray->x_hor, ray, g);
			if (ray->if_wall_hor == 0)
				ray->next_grid_hor--;
		}
	}
	get_lil_dist(ray);
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
