/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:57:22 by kmammeri          #+#    #+#             */
/*   Updated: 2022/09/21 15:52:08 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <sys/fcntl.h>

void	ft_check_texture(t_game *game, char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error:\nUnable to read texture\n", game);
	close(fd);
}

void	ft_sprite_to_img_2(t_game *g)
{
	int	size[2];

	ft_check_texture(g, g->graph->north);
	g->graph->sp_no->img = mlx_xpm_file_to_image(g->mlx_ptr, g->graph->north,
			&size[0], &size[1]);
	g->graph->sp_no->width = size[0];
	g->graph->sp_no->height = size[1];
	g->graph->sp_no->r_h = 0.5 * g->r_v / size[0];
	g->graph->sp_no->addr = mlx_get_data_addr(g->graph->sp_no->img,
			&g->graph->sp_no->b_p_pix, &g->graph->sp_no->l_len,
			&g->graph->sp_no->endian);
	ft_check_texture(g, g->graph->south);
	g->graph->sp_so->img = mlx_xpm_file_to_image(g->mlx_ptr, g->graph->south,
			&size[0], &size[1]);
	g->graph->sp_so->width = size[0];
	g->graph->sp_so->height = size[1];
	g->graph->sp_so->r_h = 0.5 * g->r_v / size[0];
	g->graph->sp_so->addr = mlx_get_data_addr(g->graph->sp_so->img,
			&g->graph->sp_so->b_p_pix, &g->graph->sp_so->l_len,
			&g->graph->sp_so->endian);
}

void	ft_sprite_to_img(t_game *g)
{
	int	size[2];

	ft_check_texture(g, g->graph->east);
	g->graph->sp_ea->img = mlx_xpm_file_to_image(g->mlx_ptr, g->graph->east,
			&size[0], &size[1]);
	g->graph->sp_ea->width = size[0];
	g->graph->sp_ea->height = size[1];
	g->graph->sp_ea->r_h = 0.5 * g->r_v / size[0];
	g->graph->sp_ea->addr = mlx_get_data_addr(g->graph->sp_ea->img,
			&g->graph->sp_ea->b_p_pix, &g->graph->sp_ea->l_len,
			&g->graph->sp_ea->endian);
	ft_check_texture(g, g->graph->west);
	g->graph->sp_we->img = mlx_xpm_file_to_image(g->mlx_ptr, g->graph->west,
			&size[0], &size[1]);
	g->graph->sp_we->width = size[0];
	g->graph->sp_we->height = size[1];
	g->graph->sp_we->r_h = 0.5 * g->r_v / size[0];
	g->graph->sp_we->addr = mlx_get_data_addr(g->graph->sp_we->img,
			&g->graph->sp_we->b_p_pix, &g->graph->sp_we->l_len,
			&g->graph->sp_we->endian);
	ft_sprite_to_img_2(g);
}

void	ft_init_mlx(t_game *g)
{
	g->mlx_ptr = mlx_init();
	g->mlx_window = mlx_new_window(g->mlx_ptr, g->w_wi, g->w_he, "cub3D");
	ft_sprite_to_img(g);
	mlx_mouse_move(g->mlx_window, g->w_wi * 0.5, g->w_he * 0.5);
	mlx_hook(g->mlx_window, 02, 1L << 0, ft_press_key, g);
	mlx_hook(g->mlx_window, 03, 1L << 1, ft_release_key, g);
	mlx_loop_hook(g->mlx_ptr, ft_action_loop, g);
	mlx_hook(g->mlx_window, 17, 1L << 17, ft_exit_game, g);
	mlx_loop(g->mlx_ptr);
}
