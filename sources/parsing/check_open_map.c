/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:00:10 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/14 17:36:28 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_square_map(t_game *game)
{
	int	len_max;
	int	y;

	y = -1;
	len_max = 0;
	while (game->map[++y])
	{
		if (ft_strlen(game->map[y]) > len_max)
			len_max = ft_strlen(game->map[y]);
	}
	y = -1;
	while (game->map[++y])
	{
		while (ft_strlen(game->map[y]) < len_max)
			game->map[y] = l_add_char(game->map[y], ' ');
	}
}


void	ft_check_open_map(t_game *game, int x, int y)
{
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if ((y == 0 || x == 0) && game->map[y][x] == '0')
				ft_print_error("Error\nOpen Map\n", game);
			if (game->map[y][x] == '0')
			{
				if (!game->map[y][x - 1] || (game->map[y][x - 1] != '1'
						&& game->map[y][x - 1] != '0'))
					ft_print_error("Error\nOpen Map\n", game);
				if (!game->map[y][x + 1] || (game->map[y][x + 1] != '1'
						&& game->map[y][x + 1] != '0'))
					ft_print_error("Error\nOpen Map\n", game);
				if (!game->map[y - 1][x] || (game->map[y - 1][x] != '1'
						&& game->map[y - 1][x] != '0')
						|| ft_strlen(game->map[y - 1]) < x)
					ft_print_error("Error\nOpen Map\n", game);
				if ((game->map[y + 1][x] != '1' && game->map[y + 1][x] != '0')
						|| ft_strlen(game->map[y + 1]) < x)
					ft_print_error("Error\nOpen Map\n", game);
			}
		}
	}
}
