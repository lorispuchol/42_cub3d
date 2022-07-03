/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:35:34 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/03 23:03:05 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>
#include <stdio.h>

// void	ft_get_next_pt_x(t_game *game, int i, float angle)
// {
// 	int	posx;
// 	int	posy;

// 	i++;
// }

void	ft_display_rays(t_game *game, int ray, float angle)
{
	t_rectangle	rect;

	game->ray->dist[0] = cosf(fabsf(angle - (float)game->player->dir)) * sqrtf((game->player->x - game->ray[ray].pt_v[0]) * (game->player->x - game->ray[ray].pt_v[0]) + (game->player->y - game->ray[ray].pt_v[1]) * (game->player->y - game->ray[ray].pt_v[1]));
	game->ray->dist[1] = cosf(fabsf(angle - (float)game->player->dir)) * sqrtf((game->player->x - game->ray[ray].pt_h[0]) * (game->player->x - game->ray[ray].pt_h[0]) + (game->player->y - game->ray[ray].pt_h[1]) * (game->player->y - game->ray[ray].pt_h[1]));
	if (angle >= game->player->dir - game->r_h && angle <= game->player->dir + game->r_h)
	{
		dprintf(2, "test4 dist hor == %f\n", game->ray->dist[0]);
		dprintf(2, "test4 dist vert == %f\n", game->ray->dist[1]);
	}
	game->ray->dist_first_wall = game->ray->dist[0];
	game->ray->first_wall = game->ray->wall[0];
	if (game->ray->dist[0] > game->ray->dist[1])
	{
		game->ray->first_wall = game->ray->wall[1];
		game->ray->dist_first_wall = game->ray->dist[1];
	}
	if (angle >= game->player->dir - game->r_h && angle <= game->player->dir + game->r_h)
		dprintf(2, "test4 dist first wall == %f\n", game->ray->dist_first_wall);
	rect.tl.x = ray;
	rect.tl.y = (int)(game->w_he * 0.5 - 15000 / (game->ray->dist_first_wall * 100));
	if (rect.tl.y < 0 || rect.tl.y > game->w_he)
		rect.tl.y = 10;
	rect.br.x = ray;
	rect.br.y = (int)(game->w_he * 0.5 + 15000 / (game->ray->dist_first_wall * 100));
	if (rect.br.y < 0 || rect.br.y > game->w_he)
		rect.br.y =  game->w_he - 10;
	if (game->ray->first_wall == 1)
		ft_rectangle(game->screen, rect, 0x00FFFFFF);
	if (game->ray->first_wall == 2)
		ft_rectangle(game->screen, rect, 0x00F5F5F5);
	if (game->ray->first_wall == 3)
		ft_rectangle(game->screen, rect, 0x00F0F0F0);
	if (game->ray->first_wall == 4)
		ft_rectangle(game->screen, rect, 0x00EAEAEA);
}

void	ft_find_wall(t_game *game, int ray, float angle, int init[2])
{
	while (game->ray[ray].first_wall == 0)
	{
		if (angle > 0 && angle < M_PI && game->ray[ray].dist[0] == 0)
		{
			game->ray[ray].wall[0] = 1;
			game->ray[ray].pt_v[1] = game->ray[ray].pt_v[1] + init[0] * tanf(angle);
		}
		else if (game->ray[ray].dist[0] == 0)
		{
			game->ray[ray].wall[0] = 2;
			game->ray[ray].pt_v[1] = game->ray[ray].pt_v[1] + init[0] * tanf(angle);
			
		}
		init[0] = 1;
		if (game->ray[ray].pt_v[1] > 0 && game->ray[ray].pt_v[0] > 0 && game->map[(int)game->ray[ray].pt_v[1]] && game->map[(int)game->ray[ray].pt_v[1]][(int)game->ray[ray].pt_v[0]])
		{
			if (angle > M_PI_2 && angle < 3 * M_PI_2)
			{
				if (game->map[(int)game->ray[ray].pt_v[1]][(int)game->ray[ray].pt_v[0]] == '1' && game->ray[ray].dist[0] == 0)
					game->ray[ray].dist[0] = sqrtf((game->player->x - game->ray[ray].pt_v[0]) * (game->player->x - game->ray[ray].pt_v[0]) + (game->player->y - game->ray[ray].pt_v[1]) * (game->player->y - game->ray[ray].pt_v[1]));
			}
			else
			{
				if (game->map[(int)game->ray[ray].pt_v[1]][(int)game->ray[ray].pt_v[0]] == '1' && game->ray[ray].dist[0] == 0)
					game->ray[ray].dist[0] = sqrtf((game->player->x - game->ray[ray].pt_v[0]) * (game->player->x - game->ray[ray].pt_v[0]) + (game->player->y - game->ray[ray].pt_v[1]) * (game->player->y - game->ray[ray].pt_v[1]));
			}
		}
		if (angle > 0 && angle < M_PI)
			game->ray[ray].pt_v[0] += 1;
		else
		 	game->ray[ray].pt_v[0] -= 1;
		if (angle > 0 && angle < M_PI)
		
	}

	// dprintf(2, "dist fisrt wall == %f\n", game->ray->dist_first_wall);
}

void	ft_init_ray(t_game *game, int ray, float angle)
{
	int	init[2];

	game->ray[ray].dist[0] = 0;
	game->ray[ray].dist[1] = 0;
	game->ray[ray].wall[0] = 0;
	game->ray[ray].wall[1] = 0;
	game->ray[ray].pt_v[0] = floorf(game->player->x) + 1;
	game->ray[ray].pt_v[1] = game->player->y;
	game->ray[ray].pt_h[0] = game->player->x;
	game->ray[ray].pt_h[1] = floorf(game->player->y) + 1;
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		game->ray[ray].pt_v[0] -= 1;
	if (angle > M_PI && angle < 2 * M_PI)
		game->ray[ray].pt_h[1] -= 1;
	init[0] = game->player->x - game->ray[ray].pt_v[0];
	init[1] = game->player->y - game->ray[ray].pt_h[1];
	ft_find_wall(game, ray, angle,  init);
}

void	ft_cast_ray(t_game *game)
{
	int		i;
	float	angle;

	angle = game->player->dir - game->fov_2;
	i = 0;
	while (angle < game->player->dir + game->fov_2 && i < game->w_wi)
	{
		if (game->player->dir > 2 * M_PI)
			game->player->dir -= 2 * M_PI;
		if (game->player->dir < 0)
			game->player->dir += 2 * M_PI;
		if (game->player->dir > M_PI - game->rot && game->player->dir < M_PI + game->rot)
			game->player->dir = M_PI;
		if (game->player->dir > 0 - game->rot && game->player->dir < 0 + game->rot)
			game->player->dir = 0;
		if (game->player->dir > M_PI_2 - game->rot && game->player->dir < M_PI_2 + game->rot)
			game->player->dir = M_PI_2;
		if (game->player->dir > 3 * M_PI_2 - game->rot && game->player->dir < 3 * M_PI_2 + game->rot)
			game->player->dir = 3 * M_PI_2;
		ft_init_ray(game, i, angle);
		// ft_display_rays(game, i, angle);
		angle += game->r_h;
		i++;
	}
}
