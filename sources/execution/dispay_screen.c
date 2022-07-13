/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:59:17 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/13 15:38:53 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

void	ft_night(t_game *g)
{
	t_rectangle	back;
	t_data		sky;
	int			xy[2];
	int			color[2];
	int			offset;

	sky.img = mlx_xpm_file_to_image(g->mlx_ptr, "./sprites/moon.xpm", &sky.width, &sky.height);
	sky.addr = mlx_get_data_addr(sky.img, &sky.b_p_pix, &sky.l_len, &sky.endian);
	offset = (g->player->dir * sky.width) / (M_PI * 2);
	xy[1] = -1;
	while (++xy[1] < g->w_he * 0.5 + (int)(sinf(g->player->tilt) * g->w_he * 0.5) - 1)
	{
		xy[0] = -1;
		color[1] = sky.height * (float)(g->w_he - g->w_he * 0.5 - (int)(sinf(g->player->tilt) * g->w_he * 0.5) + xy[1]) / (float)g->w_he;
		while (++xy[0] < g->w_wi)
		{
			color[0] = ((float)xy[0] * g->fov / ((float)g->w_wi * 2 * M_PI)) * sky.width + offset;
			if (color[0] >= sky.width)
				color[0] -=  sky.width;
			ft_set_pix(g->screen, xy[0], xy[1], ft_get_color(&sky, color[0], color[1]));
		}
	}
	back.tl.x = 0;
	back.tl.y = g->w_he * 0.5 + (int)(sinf(g->player->tilt) * g->w_he * 0.5);
	back.br.x = g->w_wi;
	back.br.y = g->w_he - 1;
	ft_rectangle(g->screen, back, g->graph->floor);
	mlx_destroy_image(g->mlx_ptr, sky.img);
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
