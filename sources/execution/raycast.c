/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:16:59 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/07/07 16:05:30 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_lil_dist(t_ray *ray, t_game *game)
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
	else if ((ray->dist_impact_ver <= 0 && ray->dist_impact_hor <= 0) || ray->dist_impact_ver == ray->dist_impact_hor)
	{
	 	ray->lil_dist = -1;
		ray->pt_impact_x = -1;
		ray->pt_impact_y = -1;
		ray->wall = -1;
	}
	else {
		ray->lil_dist = -2;
		ray->pt_impact_x = -2;
		ray->pt_impact_y = -2;
		ray->wall = -2;
	}
}

void ft_raycast_btm_rgt(t_game *g, t_ray *ray)
{
	ray->next_grid_hor = (int)floorf(g->player->y) + 1;
	ray->next_grid_ver = (int)floorf(g->player->x) + 1;
	
	// dprintf(1, "ici 1  ---  ray num: %d  ---  angle: %Lf\n", ray->index, ray->angle);
	while(ray->if_wall_ver == 0 || ray->if_wall_hor == 0)
	{
		if (ray->if_wall_ver == 0)
		{
			ray->y_ver = ((float)ray->next_grid_ver - g->player->x) * tan((double)ray->angle) + g->player->y;
			check_if_wall_ver(ray->next_grid_ver, ray->y_ver, ray, g);
			if (ray->if_wall_ver == 0)
				ray->next_grid_ver++;
		}
		if (ray->if_wall_hor == 0)
		{
			ray->x_hor = fabsf((float)ray->next_grid_hor - g->player->y) * tan(M_PI_2 - (double)ray->angle) + g->player->x;
			check_if_wall_hor(ray->next_grid_hor, ray->x_hor, ray, g);
			if (ray->if_wall_hor == 0)
				ray->next_grid_hor++;
		}
	}
	get_lil_dist(ray, g);
}

void ft_raycast_btm_lft(t_game *g, t_ray *ray)
{
	ray->next_grid_hor = (int)floorf(g->player->y) + 1;
	ray->next_grid_ver = (int)floorf(g->player->x);
	
	// dprintf(1, "ici 2  ---  ray num: %d  ---  angle: %Lf\n", ray->index, ray->angle);
	while(ray->if_wall_ver == 0 || ray->if_wall_hor == 0)
	{
		if (ray->if_wall_ver == 0)
		{
			ray->y_ver = ((float)ray->next_grid_ver - g->player->x) * tan((double)ray->angle) + g->player->y;
			check_if_wall_ver(ray->next_grid_ver, ray->y_ver, ray, g);
			if (ray->if_wall_ver == 0)
				ray->next_grid_ver--;
		}
		if (ray->if_wall_hor == 0)
		{
			ray->x_hor = fabsf((float)ray->next_grid_hor - g->player->y) * tan(M_PI_2 - (double)ray->angle) + g->player->x;
			check_if_wall_hor(ray->next_grid_hor, ray->x_hor, ray, g);
			if (ray->if_wall_hor == 0)
				ray->next_grid_hor++;
		}
	}
	get_lil_dist(ray, g);
}

void ft_raycast_top_lft(t_game *g, t_ray *ray)
{
	ray->next_grid_hor = (int)floorf(g->player->y);
	ray->next_grid_ver = (int)floorf(g->player->x);
	
	// dprintf(1, "ici 3  ---  ray num: %d  ---  angle: %Lf\n", ray->index, ray->angle);
	while(ray->if_wall_ver == 0 || ray->if_wall_hor == 0)
	{

		if (ray->if_wall_ver == 0)
		{
			ray->y_ver = ((float)ray->next_grid_ver - g->player->x) * tan((double)ray->angle) + g->player->y;
			check_if_wall_ver(ray->next_grid_ver, ray->y_ver, ray, g);
			if (ray->if_wall_ver == 0)
				ray->next_grid_ver--;
		}
		if (ray->if_wall_hor == 0)
		{
			ray->x_hor = fabsf((float)ray->next_grid_hor - g->player->y) * tan((double)ray->angle + M_PI_2) + g->player->x;
			check_if_wall_hor(ray->next_grid_hor, ray->x_hor, ray, g);
			if (ray->if_wall_hor == 0)
				ray->next_grid_hor--;
		}
	}
	get_lil_dist(ray, g);
}


void ft_raycast_top_rgt(t_game *g, t_ray *ray)
{	
	ray->next_grid_hor = (int)floorf(g->player->y);
	ray->next_grid_ver = (int)floorf(g->player->x) + 1;
	
	// dprintf(1, "ici 4  ---  ray num: %d  ---  angle: %Lf\n", ray->index, ray->angle);
	while(ray->if_wall_ver == 0 || ray->if_wall_hor == 0)
	{
		if (ray->if_wall_ver == 0)
		{
			ray->y_ver = ((float)ray->next_grid_ver - g->player->x) * tan((double)ray->angle) + g->player->y;
			check_if_wall_ver(ray->next_grid_ver, ray->y_ver, ray, g);
			if (ray->if_wall_ver == 0)
				ray->next_grid_ver++;
		}
		if (ray->if_wall_hor == 0)
		{
			ray->x_hor = fabsf((float)ray->next_grid_hor - g->player->y) * tan((double)ray->angle + M_PI_2) + g->player->x;
			check_if_wall_hor(ray->next_grid_hor, ray->x_hor, ray, g);
			if (ray->if_wall_hor == 0)
				ray->next_grid_hor--;
		}
	}
	get_lil_dist(ray, g);
}