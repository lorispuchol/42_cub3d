/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:38:54 by kmammeri          #+#    #+#             */
/*   Updated: 2022/09/21 15:26:55 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

void	ft_floor(t_game *g)
{
	int			xy[3];
	long double	raydir_xy0[4];
	long double	rowdist;
	long double	floor_step_xy[2];
	long double	floor_xy[2];

	floor1(g, xy, raydir_xy0);
	while (xy[2] < g->w_he)
	{
		xy[0] = 0;
		rowdist = g->w_he_2 / (xy[1] - g->w_he * 0.5 + 1);
		floor_step_xy[0] = rowdist * (raydir_xy0[2] - raydir_xy0[0]) / g->w_wi;
		floor_step_xy[1] = rowdist * (raydir_xy0[3] - raydir_xy0[1]) / g->w_wi;
		floor_xy[0] = g->player->x + rowdist * raydir_xy0[0];
		floor_xy[1] = g->player->y + rowdist * raydir_xy0[1];
		ft_floor2(g, floor_xy, floor_step_xy, xy);
		xy[1]++;
		xy[2]++;
	}
}

void	ft_night(t_game *g)
{
	int			xy[2];
	int			color[2];
	int			offset;

	ft_night1(g);
	offset = (g->player->dir * g->graph->sky->width) / (M_PI * 2);
	xy[1] = -1;
	while (++xy[1] < g->w_he * 0.5
		+ (int)(sinf(g->player->tilt) * g->w_he * 0.5) - 1)
	{
		xy[0] = -1;
		color[1] = g->graph->sky->height * (float)(g->w_he - g->w_he * 0.5
				- (int)(sinf(g->player->tilt) * g->w_he * 0.5)
				+ xy[1]) / (float)g->w_he;
		while (++xy[0] < g->w_wi)
		{
			color[0] = ((float)xy[0] * g->fov / ((float)g->w_wi * 2 * M_PI))
				* g->graph->sky->width + offset;
			if (color[0] >= g->graph->sky->width)
				color[0] -= g->graph->sky->width;
			ft_set_pix(g->screen, xy[0], xy[1],
				ft_get_color(g->graph->sky, color[0], color[1]));
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

void	ft_reticle(t_game	*g)
{
	t_rectangle	rect;

	rect.tl.x = g->w_wi * 0.5;
	rect.tl.y = g->w_he_2 - 20;
	rect.br.x = g->w_wi * 0.5 + 1;
	rect.br.y = g->w_he_2 - 15;
	ft_rectangle(g->screen->img, rect, 0x00ffffff);
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
	if (g->key->lock_mouse)
		ft_reticle(g);
	mlx_put_image_to_window(g->mlx_ptr, g->mlx_window, g->screen->img, 0, 0);
}
