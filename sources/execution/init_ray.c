/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:35:34 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/02 02:50:11 by kmammeri         ###   ########lyon.fr   */
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

void	ft_find_wall(t_game *game, int ray, float angle)
{
	float		pt_tmp_v[2];
	float		pt_tmp_h[2];
	float		tangle;
	t_rectangle	rect;

	tangle = angle;
	if (angle < M_PI && angle > M_PI_2)
		tangle = angle + M_PI_2;
	if (angle < M_PI * 2 && angle > M_PI_2 * 3)
		tangle = angle + M_PI_2;
	while (game->ray[ray].wall[0] == 0 && angle < M_PI * 2 && angle > M_PI)
	{
		pt_tmp_v[0] = game->ray[ray].pt_v[0];
		pt_tmp_v[1] = floorf(game->ray[ray].pt_v[1]);
		if (angle != M_PI_2 && angle != 3 * M_PI_2)
		{
			// dprintf(2, "test1 1\n");
			game->ray[ray].pt_v[0] = pt_tmp_v[0] + fabsf(game->ray[ray].pt_v[1] - pt_tmp_v[1]) * tanf(tangle + M_PI_2);
			// dprintf(2, "test2 1\n");
			game->ray[ray].pt_v[1] = pt_tmp_v[1];
			if (game->map[(int)floorf(game->ray[ray].pt_v[1]) - 1][(int)floorf(game->ray[ray].pt_v[0])] == '1' || game->ray[ray].pt_v[1] - 1 <= 0)
				game->ray[ray].wall[0] = 1;
			else
				game->ray[ray].pt_v[1] -= 1;
		}
		else 
		{
			game->ray[ray].pt_v[1] = MAXFLOAT;
			game->ray[ray].wall[0] = 1;
			dprintf(2, "test1\n");
		}
	}
	while (game->ray[ray].wall[0] == 0 && angle > 0 && angle < M_PI)
	{
		pt_tmp_v[0] = game->ray[ray].pt_v[0];
		pt_tmp_v[1] = floorf(game->ray[ray].pt_v[1]) + 1;
		if (angle != M_PI_2 && angle != 3 * M_PI_2)
		{
			// dprintf(2, "test1 2 ray == %d\n", ray);
			game->ray[ray].pt_v[0] = pt_tmp_v[0] + fabsf(game->ray[ray].pt_v[1] - pt_tmp_v[1]) * tanf(tangle);
			// dprintf(2, "test2 2 ray == %d\n", ray);
			game->ray[ray].pt_v[1] = pt_tmp_v[1];
			if (!game->map[(int)game->ray[ray].pt_v[1] + 1] || game->map[(int)floorf(game->ray[ray].pt_v[1]) + 1][(int)floorf(game->ray[ray].pt_v[0])] == '1')
				game->ray[ray].wall[0] = 2;
			else
				game->ray[ray].pt_v[1] = pt_tmp_v[1];
			// dprintf(2, "test2 2 ray == %d\n", ray);
		}
		else 
		{
			game->ray[ray].pt_v[1] = MAXFLOAT;
			game->ray[ray].wall[0] = 2;
			dprintf(2, "test2\n");
		}
	}
	while (game->ray[ray].wall[1] == 0 && angle > M_PI_2 && angle < 3 * M_PI_2)
	{
		pt_tmp_h[0] = floorf(game->ray[ray].pt_h[0]);
		pt_tmp_h[1] = game->ray[ray].pt_h[1];
		if (angle != M_PI_2 && angle != 3 * M_PI_2)
		{
			game->ray[ray].pt_h[0] = pt_tmp_h[0];
			// dprintf(2, "test1 3\n");
			game->ray[ray].pt_h[1] = pt_tmp_h[1] + fabsf(game->ray[ray].pt_h[0] - pt_tmp_h[0]) * tanf(tangle);
			// dprintf(2, "test2 3\n");
			if (game->map[(int)floorf(game->ray[ray].pt_h[1])][(int)floorf(game->ray[ray].pt_h[0]) - 1] == '1' || game->ray[ray].pt_h[0] - 1 <= 0)
				game->ray[ray].wall[1] = 1;
			else
				game->ray[ray].pt_h[0] -= 1;
		}
		else 
		{
			game->ray[ray].pt_h[0] = MAXFLOAT;
			game->ray[ray].wall[1] = 1;
			dprintf(2, "test3\n");
		}
	}
	while (game->ray[ray].wall[1] == 0 && ((angle < M_PI_2 && angle >= 0) || (angle > M_PI_2 * 3 && angle <= 2 * M_PI)))
	{
		pt_tmp_h[0] = floorf(game->ray[ray].pt_h[0]) + 1;
		pt_tmp_h[1] = game->ray[ray].pt_h[1];
		if (angle != M_PI_2 && angle != 3 * M_PI_2)
		{
			game->ray[ray].pt_h[0] = pt_tmp_h[0];
			// dprintf(2, "test1 4\n");
			game->ray[ray].pt_h[1] = pt_tmp_h[1] + fabsf(game->ray[ray].pt_h[0] - pt_tmp_h[0]) * tanf(tangle);
			// dprintf(2, "test2 4\n");
			if (game->map[(int)floorf(game->ray[ray].pt_h[1])][(int)floorf(game->ray[ray].pt_h[0]) + 1] == '1' || !game->map[(int)game->ray[ray].pt_h[1]][(int)game->ray[ray].pt_h[0]])
				game->ray[ray].wall[1] = 2;
			else
				game->ray[ray].pt_h[0] = pt_tmp_h[0];
		}
		else 
		{
			game->ray[ray].pt_h[0] = MAXFLOAT;
			game->ray[ray].wall[1] = 1;
			dprintf(2, "test4\n");
		}
	}
	if (angle != (float)game->player->dir)
	{
		game->ray->dist[0] = cosf(fabsf(angle - (float)game->player->dir)) * sqrtf((game->player->x - game->ray[ray].pt_v[0]) * (game->player->x - game->ray[ray].pt_v[0]) + (game->player->y - game->ray[ray].pt_v[1]) * (game->player->y - game->ray[ray].pt_v[1]));
		game->ray->dist[1] = cosf(fabsf(angle - (float)game->player->dir)) * sqrtf((game->player->x - game->ray[ray].pt_h[0]) * (game->player->x - game->ray[ray].pt_h[0]) + (game->player->y - game->ray[ray].pt_h[1]) * (game->player->y - game->ray[ray].pt_h[1]));
	}
	game->ray->dist_first_wall = game->ray->dist[0];
	if (game->ray->dist[0] > game->ray->dist[1])
		game->ray->dist_first_wall = game->ray->dist[1];
	rect.tl.x = ray;
	rect.tl.y = (int)(game->w_he * 0.5 - 10000 / (game->ray->dist_first_wall * 100));
	if (rect.tl.y < 0 || rect.tl.y > game->w_he)
	{
		// exit (0);
		// dprintf(2, "impact vert  x = %f | y = %f\n dist = %f\n", game->ray[ray].pt_v[0], game->ray[ray].pt_v[1], game->ray->dist[0]);
		// dprintf(2, "impact hor  x = %f | y = %f\n dist = %f\n", game->ray[ray].pt_h[0], game->ray[ray].pt_h[1], game->ray->dist[1]);
		rect.tl.y = 10;
	}
	rect.br.x = ray;
	rect.br.y = (int)(game->w_he * 0.5 + 10000 / (game->ray->dist_first_wall * 100));
	if (rect.br.y < 0 || rect.br.y > game->w_he)
		rect.br.y =  game->w_he - 10;
	ft_rectangle(game->screen, rect, 0x00FFFFFF);
	// dprintf(2, "dist fisrt wall == %f\n", game->ray->dist_first_wall);
}

void	ft_init_ray(t_game *game, int ray, float angle)
{
	// if ()
	// 	dprintf(2, "up\n");
	// if (game->player->dir > 0 && game->player->dir < M_PI)
	// 	dprintf(2, "down\n");
	// if ((game->player->dir < M_PI_2 && game->player->dir >= 0) || (game->player->dir > M_PI_2 * 3 + 0.000001 && game->player->dir <= 2 * M_PI))
	// 	dprintf(2, "right\n");
	// if (game->player->dir > M_PI_2 + 0.00001 && game->player->dir < 3 * M_PI_2)
	// 	dprintf(2, "left\n");
	game->ray[ray].dist[0] = 0;
	game->ray[ray].dist[1] = 0;
	game->ray[ray].wall[0] = 0;
	game->ray[ray].wall[1] = 0;
	game->ray[ray].pt_v[0] = game->player->x;
	game->ray[ray].pt_v[1] = game->player->y;
	game->ray[ray].pt_h[0] = game->player->x;
	game->ray[ray].pt_h[1] = game->player->y;
	ft_find_wall(game, ray, angle);
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
		// ft_get_next_pt_x(game, i, angle);
		angle += game->r_h;
		i++;
	}
}
