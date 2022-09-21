/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:39:43 by lpuchol           #+#    #+#             */
/*   Updated: 2022/09/21 14:27:38 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <sys/fcntl.h>

void	ft_destroy_walls(t_game *game)
{
	if (game->graph->sp_ea->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->sp_ea->img);
	if (game->graph->sp_so->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->sp_so->img);
	if (game->graph->sp_no->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->sp_no->img);
	if (game->graph->sp_we->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->sp_we->img);
	if (game->graph->ground->img)
		mlx_destroy_image(game->mlx_ptr, game->graph->ground->img);
}

void	ft_img_walls(t_game *g)
{
	ft_sprite_to_img(g);
	if (!g->key->animated_sprite || !g->graph->ground->img)
	{
		g->graph->ground->img = mlx_xpm_file_to_image(g->mlx_ptr,
			"./sprites/stone_floor.xpm", &g->graph->ground->width,
			&g->graph->ground->height);
		g->graph->ground->addr = mlx_get_data_addr(g->graph->ground->img,
			&g->graph->ground->b_p_pix, &g->graph->ground->l_len,
			&g->graph->ground->endian);
	}
	if (!g->graph->sp_ea->img || !g->graph->sp_we->img
		|| !g->graph->sp_no->img || !g->graph->sp_so->img)
		ft_print_error("Error :\nUnable to read wall texture\n", g);
}

void	ft_animated_walls(t_game *g)
{
	char	*str;
	char	*tmp;
	int		fd;

	fd = 0;
	str = ft_strdup("./sprites/animation/gif");
	if (g->frame >= NB_FRAME_ANIMATION)
		g->frame = 0;
	tmp = ft_itoa(g->frame);
	str = ft_strjoin(str, tmp);
	free(tmp);
	str = ft_strjoin(str, ".xpm");
	fd = open(str, O_RDONLY);
	if (fd > 0)
	{
		close(fd);

		g->graph->sp_ea->img = mlx_xpm_file_to_image(g->mlx_ptr, str,
				&g->graph->sp_ea->width, &g->graph->sp_ea->height);
		g->graph->sp_ea->r_h = 0.5 * g->r_v / g->graph->sp_ea->width;
		g->graph->sp_ea->addr = mlx_get_data_addr(g->graph->sp_ea->img,
				&g->graph->sp_ea->b_p_pix, &g->graph->sp_ea->l_len,
				&g->graph->sp_ea->endian);

		g->graph->sp_we->img = mlx_xpm_file_to_image(g->mlx_ptr, str,
				&g->graph->sp_we->width, &g->graph->sp_we->height);
		g->graph->sp_we->r_h = 0.5 * g->r_v / g->graph->sp_we->width;
		g->graph->sp_we->addr = mlx_get_data_addr(g->graph->sp_we->img,
				&g->graph->sp_we->b_p_pix, &g->graph->sp_we->l_len,
				&g->graph->sp_we->endian);

		g->graph->sp_no->img = mlx_xpm_file_to_image(g->mlx_ptr, str,
				&g->graph->sp_no->width, &g->graph->sp_no->height);
		g->graph->sp_no->r_h = 0.5 * g->r_v / g->graph->sp_no->width;
		g->graph->sp_no->addr = mlx_get_data_addr(g->graph->sp_no->img,
				&g->graph->sp_no->b_p_pix, &g->graph->sp_no->l_len,
				&g->graph->sp_no->endian);

		g->graph->sp_so->img = mlx_xpm_file_to_image(g->mlx_ptr, str,
				&g->graph->sp_so->width, &g->graph->sp_so->height);
		g->graph->sp_so->r_h = 0.5 * g->r_v / g->graph->sp_so->width;
		g->graph->sp_so->addr = mlx_get_data_addr(g->graph->sp_so->img,
				&g->graph->sp_so->b_p_pix, &g->graph->sp_so->l_len,
				&g->graph->sp_so->endian);

		g->graph->ground->img = mlx_xpm_file_to_image(g->mlx_ptr, str,
				&g->graph->ground->width, &g->graph->ground->height);
		g->graph->ground->r_h = 0.5 * g->r_v / g->graph->ground->width;
		g->graph->ground->addr = mlx_get_data_addr(g->graph->ground->img,
				&g->graph->ground->b_p_pix, &g->graph->ground->l_len,
				&g->graph->ground->endian);
		free(str);
		if (!g->graph->sp_ea->img || !g->graph->sp_we->img
			|| !g->graph->sp_no->img || !g->graph->sp_so->img || !g->graph->ground->img)
			ft_img_walls(g);
	}
	else
	{
		close(fd);
		g->graph->ground->img = NULL;
		free(str);
		ft_img_walls(g);
	}
}

void	ft_press_key_3(t_game *game, int keycode)
{
	if (keycode == 46 && game->key->mn_map == 0)
		game->key->mn_map = 1;
	else if (keycode == 46 && game->key->mn_map == 1)
	{
		if (game->mn_map->img)
			mlx_destroy_image(game->mlx_ptr, game->mn_map->img);
		game->mn_map->img = NULL;
		game->mn_map->addr = NULL;
		game->key->mn_map = 0;
	}
	if (keycode == 7 && game->key->animated_sprite == 0 && game->key->night_mode)
	{
		game->key->animated_sprite = 1;
		ft_destroy_walls(game);
		ft_animated_walls(game);
	}
	else if (keycode == 7 && game->key->animated_sprite == 1 && game->key->night_mode)
	{
		game->key->animated_sprite = 0;
		ft_destroy_walls(game);
		ft_img_walls(game);
	}
}

int	ft_action_loop_2(t_game *game)
{
	if (game->key->lock_mouse == 1)
	{
		if (game->key->hide_show_mouse == 0)
			game->key->hide_show_mouse = mlx_mouse_show() * 0 + 1;
	}
	else if (game->key->lock_mouse == 0)
		ft_mouse_directions(game);
	if (game->key->animated_sprite && game->key->night_mode)
	{
		if (game->timer < TIME_ANIME)
			game->timer += 1;
		if (game->timer >= TIME_ANIME)
		{
			game->frame += 1;
			game->timer = 0;
			ft_destroy_walls(game);
			ft_animated_walls(game);
		}
	}
	return (0);
}
