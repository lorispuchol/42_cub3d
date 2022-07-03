/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:00:10 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/03 22:44:20 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_square_map(t_game *game)
{
	int	len_max;
	int	y;

	y = -1;
	len_max = 0;
	while (game->map[++y])
	{
		if ((int)ft_strlen(game->map[y]) > len_max)
			len_max = ft_strlen(game->map[y]);
	}
	y = -1;
	while (game->map[++y])
	{
		while ((int)ft_strlen(game->map[y]) < len_max)
			game->map[y] = l_add_char(game->map[y], ' ');
	}
	game->l_map = ft_strlen(game->map[0]);	
	y = 0;
	while(game->map[y])
		y++;
	game->h_map = y;
}

void	ft_check_open_map(t_game *game, int x, int y)
{
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if ((y == 0 || x == 0) && game->map[y][x] == '0')
				ft_print_error("Error\nMap Opened\n", game);
			if (game->map[y][x] == '0')
			{
				if (!game->map[y][x - 1] || (game->map[y][x - 1] != '1'
						&& game->map[y][x - 1] != '0'))
					ft_print_error("Error\nMap Opened\n", game);
				if (!game->map[y][x + 1] || (game->map[y][x + 1] != '1'
						&& game->map[y][x + 1] != '0'))
					ft_print_error("Error\nMap Opened\n", game);
				if (!game->map[y - 1][x] || (game->map[y - 1][x] != '1'
						&& game->map[y - 1][x] != '0')
						|| (int)ft_strlen(game->map[y - 1]) < x)
					ft_print_error("Error\nMap Opened\n", game);
				if ((game->map[y + 1][x] != '1' && game->map[y + 1][x] != '0')
						|| (int)ft_strlen(game->map[y + 1]) < x)
					ft_print_error("Error\nMap Opened\n", game);
			}
		}
	}
}
