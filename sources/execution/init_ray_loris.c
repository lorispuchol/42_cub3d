/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_loris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:35:34 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/06 22:21:43 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
/*
void	ft_get_coef_dir(t_game *game, int i, float angle)
{
	int	posx;
	int	posy;

	i++;
	posx = game->player->x + cosf(angle);
	posy = game->player->y + sinf(angle);
	game->ray[i].cdirx = (posy - game->player->y) / (posx - game->player->y);
}
*/

void	fill_ray_ver(t_ray *ray, t_game *game, int next_grid_ver, float y_ver)
{
	ray->dist_impact_ver = sqrt(powf(game->player->x - next_grid_ver, 2) + powf(game->player->y - y_ver, 2));
	ray->if_wall_ver = 1;
	if (ray->angle > M_PI_2 && ray->angle < M_PI_2 * 3)
		ray->wall_ver = SP_EAST;
	else if ((ray->angle > 0 && ray->angle < M_PI_2) || (ray->angle > 3 * M_PI_2 && ray->angle < 2 * M_PI))
		ray->wall_ver = SP_WEST;
}

void	fill_ray_hor(t_ray *ray, t_game *game, int next_grid_hor, float x_hor)
{
	ray->dist_impact_hor = sqrt(powf(game->player->y - next_grid_hor, 2) + powf(game->player->x - x_hor, 2));
	ray->if_wall_hor = 1;
	if (ray->angle > M_PI && ray->angle < M_PI * 2)
		ray->wall_hor = SP_SOUTH;
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->wall_hor = SP_NORTH;
}

void	check_if_wall_ver(int next_grid_ver, float y_ver, t_ray *ray, t_game *game)
{
	if (y_ver < 0 || y_ver > (game->h_map - 1))
	{
		ray->dist_impact_ver = -1;
		ray->if_wall_ver = -1;
		return ;	
	}
	if (ray->angle > M_PI_2 && ray->angle < 3 * M_PI_2)
	{	
		if (game->map[(int)floorf(y_ver)][next_grid_ver - 1] == '1')
		{
			fill_ray_ver(ray, game, next_grid_ver, y_ver);
			return ;
		}
	}
	else if ((ray->angle > 0 && ray->angle < M_PI_2) || (ray->angle > 3 * M_PI_2 && ray->angle < 2 * M_PI))
	{
		if (game->map[(int)floorf(y_ver)][next_grid_ver] == '1')
		{
			fill_ray_ver(ray, game, next_grid_ver, y_ver);
			return ;	
		}
	}
	return ;
}

void	check_if_wall_hor(int next_grid_hor, float x_hor, t_ray *ray, t_game *game)
{
	if (x_hor < 0 || x_hor > (game->l_map - 1))
	{
		ray->dist_impact_hor = -1;
		ray->if_wall_hor = -1;
		return ;
	}
	if (ray->angle > M_PI && ray->angle < (2 * M_PI))
	{	
		if (game->map[next_grid_hor - 1][(int)floorf(x_hor)] == '1')
		{
			fill_ray_hor(ray, game, next_grid_hor, x_hor);
			return ;
		}
	}
	else if ((ray->angle > 0 && ray->angle < M_PI))
	{
		if (game->map[next_grid_hor][(int)floorf(x_hor)] == '1')
		{
			fill_ray_hor(ray, game, next_grid_hor, x_hor);
			return ;
		}
	}
	return ;
}



void ft_raycast(t_game *game, long double angle, t_ray *ray)
{
	int next_grid_hor;
	int next_grid_ver;
	float first_cross_hor;
	float first_cross_ver;

	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle == 0 || angle == 3 * M_PI_2 || angle == M_PI_2 || angle == 2 * M_PI || angle == M_PI || angle == -M_PI)
	{
		// ft_angle_particulier();
		dprintf(1, "dir on axe\n");
		return ;
	}	
	
	if (angle > 0 && angle < M_PI_2)
		ft_raycast_btm_rgt(game, ray);
	else if (angle > M_PI_2 && angle < M_PI)
		ft_raycast_btm_lft(game, ray);
	else if (angle > M_PI && angle < 3 * M_PI_2)
		ft_raycast_top_lft(game, ray);
	else if (angle > 3 * M_PI_2 && angle < 2 * M_PI)
		ft_raycast_top_rgt(game, ray);
	
	/*
	if (angle > M_PI && angle < (2 * M_PI))
		next_grid_hor = (int)floorf(game->player->y);
	else if (angle > 0 && angle < M_PI)
		next_grid_hor = (int)floorf(game->player->y) + 1;
	if (angle > M_PI_2 && angle < (3 * M_PI_2))
		next_grid_ver = (int)floorf(game->player->x);
	else if ((angle >= 0 && angle < M_PI_2) || (angle > (3 * M_PI_2) && angle <= (2 * M_PI)))
		next_grid_ver = (int)floorf(game->player->x) + 1;

	first_cross_ver = ((float)next_grid_ver - game->player->x) * tan((double)angle) + game->player->y;
	if (angle > M_PI && angle < 2 * M_PI)
		first_cross_hor = fabsf((float)next_grid_hor - game->player->y) * tan((double)angle + M_PI_2) + game->player->x;
	else if (angle > 0 && angle < M_PI)
		first_cross_hor = fabsf((float)next_grid_hor - game->player->y) * tan(M_PI_2 - (double)angle) + game->player->x;
	else
		first_cross_hor = 0;
	*/
	
	// if (angle < game->player->dir + game->angle_rays && angle > game->player->dir - game->angle_rays)
	// {
	// 	dprintf(1, "angle == dir ::: ver wall : %d  ",  check_if_wall_ver(next_grid_ver, first_cross_ver, angle, game));
	// 	dprintf(1, "hor wall : %d\n",  check_if_wall_hor(next_grid_hor, first_cross_hor, angle, game));
	// }
	// if (angle < game->player->dir - game->fov_2 + game->angle_rays)
	// {
	// 	dprintf(1, "angle == left ::: ver wall : %d  ",  check_if_wall_ver(next_grid_ver, first_cross_ver, angle, game));
	// 	dprintf(1, "hor wall : %d\n",  check_if_wall_hor(next_grid_hor, first_cross_hor, angle, game));
	// }


/*
	if (angle > game->player->dir - game->fov_2 - game->angle_rays)
	{
		dprintf(1, "angle == right ::: ver wall : %d  ",  check_if_wall_ver(next_grid_ver, first_cross_ver, ray, game));
		dprintf(1, "hor wall : %d\n",  check_if_wall_hor(next_grid_hor, first_cross_hor, ray, game));
	}
*/

	// ft_set_pix(game->mn_map, game->mn_map->width * 0.5 + 10, game->mn_map->height * 0.5 + 10, 0x000000FF);
	// dprintf(1,"pix posi: %d\n", (int)floorf((next_grid_ver - game->player->x)));
	// dprintf(1, "premier croisement ver: x=%d y=%f  ---  premier croisement hor: x=%f y=%d  ---  posi x: %f  posi y: %f  dir: %Lf\n", next_grid_ver, first_cross_ver, first_cross_hor, next_grid_hor, game->player->x, game->player->y, angle);

	dprintf(2, "len ray: %f  wall x: %f --- wall y: %f on wall: %d ---- player x: %f  player y: %f  dir: %Lf\n", ray->lil_dist, ray->pt_impact_x, ray->pt_impact_y, ray->wall, game->player->x, game->player->y, game->player->dir);
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
		game->ray[i].angle = game->player->dir;
		ft_raycast(game, game->player->dir, &game->ray[i]);
		angle += game->angle_rays;
		i++;
	}
}
