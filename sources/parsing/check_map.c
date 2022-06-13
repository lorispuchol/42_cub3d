/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:48:00 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/13 23:32:11 by kmammeri         ###   ########.fr       */
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
					ft_print_error("Error\nInvalide map\n", game);
				game->player->x = x;
				game->player->y = y;
				// if (game->map[y][x] == 'N')
				// 	game->player->dir = pi /
			}
			x++;
		}
		y++;
	}
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
}