/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:11:36 by lorispuchol       #+#    #+#             */
/*   Updated: 2022/07/22 04:15:54 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

int	x_col(t_game *g, int x, t_data *sprite)
{
	int	color_x;

	color_x = (int)((g->ray[x].pt_impact_x
				- floorf(g->ray[x].pt_impact_x)
				+ g->ray[x].pt_impact_y
				- floorf(g->ray[x].pt_impact_y)) * sprite->width);
	return (color_x);
}

// void	ft_print_floor_texture(t_game *g, int x, int y)
// {
// 	long double	angle;
// 	// long double	true_dist;
// 	long double	dist;
// 	long double	weight;
// 	long double	current[2];
// 	int			color[2];

// 	if (g->key->night_mode == 0)
// 		return ;
// 	if (!g->graph->ground->img)
// 		g->graph->ground->img = mlx_xpm_file_to_image(g->mlx_ptr, "./sprites/real_true_wall.xpm", &g->graph->ground->width, &g->graph->ground->height);
// 	if (!g->graph->ground->addr)
// 		g->graph->ground->addr = mlx_get_data_addr(g->graph->ground->img, &g->graph->ground->b_p_pix, &g->graph->ground->l_len, &g->graph->ground->endian);
// 	angle = fabsl(g->player->dir - g->ray[x].angle);
// 	while (y < g->w_he - 1)
// 	{
// 		// dist = (long double)(g->r_v * 0.1 * 0.5 * g->graph->ground->height) / (long double)(y - 0.5 * g->w_he);
// 		dist = (long double)g->graph->ground->height / (2 * y - g->w_he);
// 		weight = dist / g->ray[x].lil_dist;
// 		// true_dist = dist / cosf(angle);
// 		// color[0] = (int)((g->player->x  + cosf(g->player->dir) * true_dist)) % g->graph->ground->width;
// 		// color[1] = (int)((g->player->y  - sinf(g->player->dir) * true_dist)) % g->graph->ground->height;
// 		current[0] = weight * g->ray[x].pt_impact_x + (1 - weight) * (g->player->x - floorf(g->player->x)) * 10;
// 		current[1] = weight *  g->ray[x].pt_impact_y + (1 - weight) * (g->player->y - floorf(g->player->y)) * 10;
// 		color[0] = (int)(current[0] * g->graph->ground->width) % g->graph->ground->width;
// 		color[1] = (int)(current[0] * g->graph->ground->height) % g->graph->ground->height;
// 		while (color[1] >= g->graph->ground->height)
// 			color[1] -= g->graph->ground->height;
// 		while (color[1] < 0)
// 			color[1] += g->graph->ground->height;
// 		while (color[0] >= g->graph->ground->width)
// 			color[0] -= g->graph->ground->width;
// 		while (color[0] < 0)
// 			color[0] += g->graph->ground->width;
// 		ft_set_pix(g->screen, x, y, ft_get_color(g->graph->ground, color[0], color[1]));
// 		y++;
// 	}
// }

void	ft_print_floor_texture2(t_game *g, int x, int y)
{
	int		color[2];
	float	dx_player_world;
	float	dy_player_world;
	float	d_dist;
	float	dist;
	// float	tmp_dist;
	// float	angle;

	if (g->key->night_mode == 0 || y >= g->w_he)
		return ;
	if (!g->graph->ground->img)
		g->graph->ground->img = mlx_xpm_file_to_image(g->mlx_ptr, "./sprites/dirt.xpm", &g->graph->ground->width, &g->graph->ground->height);
	if (!g->graph->ground->addr)
		g->graph->ground->addr = mlx_get_data_addr(g->graph->ground->img, &g->graph->ground->b_p_pix, &g->graph->ground->l_len, &g->graph->ground->endian);
	d_dist = (g->ray[x].lil_dist - 1) / (g->w_he - y);
	dist = g->ray[x].lil_dist;
	while (y < g->w_he)
	{
		// angle = fabsl(M_PI_2 * 5 - atanf(g->r_v / (float)(y - g->w_he * 0.5)));
		// tmp_dist = dist / sinf(angle);
		dx_player_world = g->player->x - floorf(g->player->x) + cosf(g->ray[x].angle) * dist ;
		dy_player_world = g->player->y - floorf(g->player->y) + sinf(g->ray[x].angle) * dist ;
		color[0] = dx_player_world * (float)g->graph->ground->width;
		color[1] = dy_player_world * (float)g->graph->ground->height;
		while (color[1] >= g->graph->ground->height)
			color[1] -= g->graph->ground->height;
		while (color[1] < 0)
			color[1] += g->graph->ground->height;
		while (color[0] >= g->graph->ground->width)
			color[0] -= g->graph->ground->width;
		while (color[0] < 0)
			color[0] += g->graph->ground->width;
		ft_set_pix(g->screen, x, y, ft_get_color(g->graph->ground, color[0], color[1]));
		y++;
		dist = dist - d_dist;
	}
}

void	print_sprite_ray(t_game *g, int x, int height_wall, t_data *sp)
{
	int	y[2];
	int	ycol;
	int	true_y;

	height_wall = height_wall * sp->r_h;
	y[0] = g->w_he * 0.5 - height_wall * 0.5
		+ (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	true_y = 0;
	if (y[0] < 0)
		y[0] = 0;
	y[1] = g->w_he * 0.5 + height_wall * 0.5
		+ (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	if (y[1] > g->w_he)
		y[1] = g->w_he;
	if (height_wall > g->screen->height
		+ (int)(sinf(g->player->tilt) * g->w_he))
		true_y = height_wall * 0.5 - g->screen->height
			* 0.5 - (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	while (y[0] < y[1])
	{
		ycol = (int)(((float)true_y / (float)height_wall) * sp->height);
		ft_set_pix(g->screen, x, y[0], ft_get_color(sp, x_col(g, x, sp), ycol));
		y[0]++;
		true_y++;
	}
	// ft_print_floor_texture(g, x, y[0]);
	ft_print_floor_texture2(g, x, y[0]);
}

void	ft_print_ray(t_game *game)
{
	float		good_dist;
	int			height_wall;
	int			i;

	i = -1;
	while (++i < game->w_wi)
	{
		good_dist = cosf(fabs((double)game->ray[i].angle
					- (double)game->player->dir)) * game->ray[i].lil_dist;
		height_wall = (int)((float)game->w_he / (good_dist));
		// game->ray[i].lil_dist = good_dist;
		if (game->ray[i].wall == SP_EAST)
			print_sprite_ray(game, i, height_wall, game->graph->sp_ea);
		if (game->ray[i].wall == SP_NORTH)
			print_sprite_ray(game, i, height_wall, game->graph->sp_no);
		if (game->ray[i].wall == SP_SOUTH)
			print_sprite_ray(game, i, height_wall, game->graph->sp_so);
		if (game->ray[i].wall == SP_WEST)
			print_sprite_ray(game, i, height_wall, game->graph->sp_we);
	}
}
