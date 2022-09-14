/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:38:54 by kmammeri          #+#    #+#             */
/*   Updated: 2022/09/14 16:39:33 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

void	ft_floor(t_game *g)
{
	int		xy[2];
	long double	raydir_xy0[2];
	long double	raydir_xy1[2];
	int		p;
	long double	posz;
	long double	rowdist;
	long double	floor_step_xy[2];
	long double	floor_xy[2];
	int		cell_xy[2];
	int		t_xy[2];
	int		y_true;

	if (!g->graph->ground->img)
		g->graph->ground->img = mlx_xpm_file_to_image(g->mlx_ptr, "./sprites/stone_floor.xpm", &g->graph->ground->width, &g->graph->ground->height);
	if (!g->graph->ground->addr)
		g->graph->ground->addr = mlx_get_data_addr(g->graph->ground->img, &g->graph->ground->b_p_pix, &g->graph->ground->l_len, &g->graph->ground->endian);
	xy[0] = 0;
	xy[1] = g->w_he * 0.5 + 1;
	y_true = g->w_he * 0.5 + (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	raydir_xy0[0] = cosf(g->player->dir) - cosf(g->player->dir + M_PI_2) * 0.65;
	raydir_xy0[1] = sinf(g->player->dir) - sinf(g->player->dir + M_PI_2) * 0.65;
	raydir_xy1[0] = cosf(g->player->dir) + cosf(g->player->dir + M_PI_2) * 0.65;
	raydir_xy1[1] = sinf(g->player->dir) + sinf(g->player->dir + M_PI_2) * 0.65;
	posz = g->w_he * 0.5;
	while (y_true < g->w_he)
	{
		xy[0] = 0;
		p = xy[1] - g->w_he * 0.5 + 1;
		rowdist = posz / p;
		floor_step_xy[0] = rowdist * (raydir_xy1[0] - raydir_xy0[0]) / g->w_wi;
		floor_step_xy[1] = rowdist * (raydir_xy1[1] - raydir_xy0[1]) / g->w_wi;
		floor_xy[0] = g->player->x + rowdist * raydir_xy0[0];
		floor_xy[1] = g->player->y + rowdist * raydir_xy0[1];
		while (xy[0] < g->w_wi)
		{
			cell_xy[0] = (int)floor_xy[0];
			cell_xy[1] = (int)floor_xy[1];
			t_xy[0] = (int)(g->graph->ground->width * (floor_xy[0] - cell_xy[0]));
			t_xy[1] = (int)(g->graph->ground->height * (floor_xy[1] - cell_xy[1]));
			while (t_xy[1] >= g->graph->ground->height)
				t_xy[1] -= g->graph->ground->height;
			while (t_xy[1] < 0)
				t_xy[1] += g->graph->ground->height;
			while (t_xy[0] >= g->graph->ground->width)
				t_xy[0] -= g->graph->ground->width;
			while (t_xy[0] < 0)
				t_xy[0] += g->graph->ground->width;
			floor_xy[0] += floor_step_xy[0];
			floor_xy[1] += floor_step_xy[1];
			ft_set_pix(g->screen, xy[0], y_true, ft_get_color(g->graph->ground, t_xy[0], t_xy[1]));

			xy[0]++;
		}
		xy[1]++;
		y_true++;
	}
}

void	ft_night(t_game *g)
{
	int			xy[2];
	int			color[2];
	int			offset;

	if (!g->graph->sky->img)
		g->graph->sky->img = mlx_xpm_file_to_image(g->mlx_ptr, "./sprites/full_sun.xpm", &g->graph->sky->width, &g->graph->sky->height);
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
		back.br.x = g->w_wi - 1;
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
