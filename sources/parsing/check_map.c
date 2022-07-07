/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:48:00 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/07 14:39:51 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_forbidden_char(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!ft_strchr(" \t\v\f\r\n10NSEW", game->map[y][x]))
				ft_print_error("Error\nInvalide map\n", game);
			x++;
		}
		y++;
	}
}

void	ft_get_player_pos(t_game *game, int x, int y)
{
	game->player->x = x + 0.5;
	game->player->y = y + 0.5;
	if (game->map[y][x] == 'N')
		game->player->dir = 3 * M_PI_2;
	if (game->map[y][x] == 'S')
		game->player->dir = M_PI_2;
	if (game->map[y][x] == 'E')
		game->player->dir = 0;
	if (game->map[y][x] == 'W')
		game->player->dir = M_PI;
	game->player->dir = M_PI_2 - 1; 
	game->map[y][x] = '0';
}

void	ft_check_multiple_spawn(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("NSEW", game->map[y][x]))
			{
				if (game->player->x != -1)
					ft_print_error("Error\nMultiple spawn in the map\n", game);
				ft_get_player_pos(game, x, y);
			}
			x++;
		}
		y++;
	}
	if (game->player->x == -1)
		ft_print_error("Error\nNo spawn in the map\n", game);
}

void	ft_check_multiple_map(t_game *game)
{
	int	y;
	int	check;

	y = 0;
	check = 0;
	while (game->map[y])
	{
		if (empty_line(game->map[y]) == EXIT_SUCCESS)
			check++;
		else if (empty_line(game->map[y]) == EXIT_FAILURE && check > 0)
			ft_print_error("Error\nInvalide map\n", game);
		y++;
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_forbidden_char(game);
	ft_check_multiple_map(game);
	ft_check_multiple_spawn(game);
	ft_check_open_map(game, -1, -1);
}
