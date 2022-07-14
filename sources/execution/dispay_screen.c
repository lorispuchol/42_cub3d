/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:59:17 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/14 03:05:58 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

void	ft_floor(t_game *g)
{
	int	xy[2];
	int	color[2];
	int	offset[2];
	float	y_2;
	int		x_len;
	int		i;

	if (!g->graph->ground->img)
		g->graph->ground->img = mlx_xpm_file_to_image(g->mlx_ptr, "./sprites/dirt.xpm", &g->graph->ground->width, &g->graph->ground->height);
	if (!g->graph->ground->addr)
		g->graph->ground->addr = mlx_get_data_addr(g->graph->ground->img, &g->graph->ground->b_p_pix, &g->graph->ground->l_len, &g->graph->ground->endian);
	offset[0] = (g->player->x - floorf(g->player->x)) * g->graph->ground->width;
	offset[1] = (g->player->y - floorf(g->player->y)) * g->graph->ground->height;
	xy[1] = g->w_he - 1;
	y_2 = g->w_he * 0.5 - (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	y_2 = y_2 * 0.5;
	dprintf(1, "y_2 == %f\n", y_2);
	x_len = g->w_wi;
	i = 0;
	// dprintf(1, "width == %d  || height == %d\n", g->graph->ground->width, g->graph->ground->height);
	// exit(0);
	while (xy[1] > g->w_he * 0.5 + (int)(sinf(g->player->tilt) * g->w_he * 0.5))
	{
		if (i == (int)y_2)
		{
			y_2 = y_2 * 0.5;
			if (y_2 == 0)
				y_2 = 1;
			i = 0;
		}
		color[1] = (int)(((float)i / (float)y_2) * g->graph->ground->height) - offset[1] * 0.8;
		while (color[1] >= g->graph->ground->height)
			color[1] -= g->graph->ground->height;
		while (color[1] < 0)
			color[1] += g->graph->ground->height;
		xy[0] = 0;
		while (xy[0] < g->w_wi)
		{
			color[0] = (int)(((float)(xy[0] - (g->w_wi - x_len) * 0.5) / (float)x_len) * g->graph->ground->width) - offset[0] * 0.8;
			while (color[0] >= g->graph->ground->width)
				color[0] -=  g->graph->ground->width;
			while (color[0] < 0)
				color[0] +=  g->graph->ground->width;
			// dprintf(1, "x color == %d  || y color == %d\n", color[0], color[1]);
			// dprintf(1, "x == %d  || y == %d\n", xy[0], xy[1]);
			ft_set_pix(g->screen, xy[0], xy[1], ft_get_color(g->graph->sp_ea, color[0], color[1]));
			xy[0]++;
		}
		// exit(0);
		x_len -= 2;
		if (x_len == 0)
			x_len = 1;
		xy[1]--;
		i++;
	}
}

void	ft_night(t_game *g)
{
	// t_rectangle	back;
	int			xy[2];
	int			color[2];
	int			offset;

	if (!g->graph->sky->img)
		g->graph->sky->img = mlx_xpm_file_to_image(g->mlx_ptr, "./sprites/moon.xpm", &g->graph->sky->width, &g->graph->sky->height);
	if (!g->graph->sky->addr)
		g->graph->sky->addr = mlx_get_data_addr(g->graph->sky->img, &g->graph->sky->b_p_pix, &g->graph->sky->l_len, &g->graph->sky->endian);
	offset = (g->player->dir * g->graph->sky->width) / (M_PI * 2);
	xy[1] = -1;
	while (++xy[1] < g->w_he * 0.5 + (int)(sinf(g->player->tilt) * g->w_he * 0.5) - 1)
	{
		xy[0] = -1;
		color[1] = g->graph->sky->height * (float)(g->w_he - g->w_he * 0.5 - (int)(sinf(g->player->tilt) * g->w_he * 0.5) + xy[1]) / (float)g->w_he;
		while (++xy[0] < g->w_wi)
		{
			color[0] = ((float)xy[0] * g->fov / ((float)g->w_wi * 2 * M_PI)) * g->graph->sky->width + offset;
			if (color[0] >= g->graph->sky->width)
				color[0] -=  g->graph->sky->width;
			ft_set_pix(g->screen, xy[0], xy[1], ft_get_color(g->graph->sky, color[0], color[1]));
		}
	}
	ft_floor(g);
	// back.tl.x = 0;
	// back.tl.y = g->w_he * 0.5 + (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	// back.br.x = g->w_wi;
	// back.br.y = g->w_he - 1;
	// ft_rectangle(g->screen, back, g->graph->floor);
}

void	ft_sky_floor(t_game *g)
{
	t_rectangle	back;
	int			fd;

	fd = open("./sprites/dark_sky.xpm", O_RDONLY);
	if (g->key->night_mode == 0 || fd == -1)
	{
		back.tl.x = 0;
		back.tl.y = 0;
		back.br.x = g->w_wi;
		back.br.y = g->w_he * 0.5 - 1
			+ (int)(sinf(g->player->tilt) * g->w_he * 0.5);
		ft_rectangle(g->screen, back, g->graph->ceiling);
		back.tl.x = 0;
		back.tl.y = g->w_he * 0.5
			+ (int)(sinf(g->player->tilt) * g->w_he * 0.5);
		back.br.x = g->w_wi;
		back.br.y = g->w_he - 1;
		ft_rectangle(g->screen, back, g->graph->floor);
	}
	else
	{
		close(fd);
		ft_night(g);
	}
}

void	ft_display_screen(t_game *g)
{	
	if (!g->screen->img)
		g->screen->img = mlx_new_image(g->mlx_ptr, g->w_wi, g->w_he);
	if (!g->screen->addr)
		g->screen->addr = mlx_get_data_addr(g->screen->img,
				&g->screen->b_p_pix, &g->screen->l_len, &g->screen->endian);
	ft_sky_floor(g);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->screen->img, 0, 0);
	ft_init_ray(g);
	ft_print_ray(g);
	ft_reset_rays(g);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->screen->img, 0, 0);
}
