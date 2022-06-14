/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:50:03 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/14 18:18:19 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	l_non_null_value(t_game *game)
{
	// dprintf(1, "north : %s\n", game->graph->north);
	// dprintf(1, "south : %s\n", game->graph->south);
	// dprintf(1, "east : %s\n", game->graph->east);
	// dprintf(1, "west : %s\n", game->graph->west);
	// dprintf(1, "ceiling : %u\n", game->graph->ceiling);
	// dprintf(1, "floor : %u\n", game->graph->floor);
	if (!game->graph->north
		|| !game->graph->south
		|| !game->graph->east
		|| !game->graph->west
		|| game->graph->ceiling < 0x00FFFFFF
		|| game->graph->floor <= 0x00FFFFFF)
		ft_print_error("Error\nMissing texture in the '.cub' file\n", game);
}

int	ft_is_a_texture(char *line, char *initials, char **texture, t_game *game)
{
	int	i;

	i = 2;
	if (ft_strncmp(line, initials, 2) == 0 && !*texture)
	{
		if (!ft_strchr(" \t\v\f\r", line[i]))
			ft_print_error("Error\nUnreadable texture\n", game);
		while (ft_strchr(" \t\v\f\r", line[i]))
			i++;
		while (!ft_strchr(" \t\v\f\r\n", line[i]))
		{
			*texture = l_add_char(*texture, line[i]);
			i++;
		}
		while (ft_strchr(" \t\v\f\r", line[i]))
			i++;
		if (line[i] != '\n')
			ft_print_error("Error\nUnreadable texture\n", game);
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(line, initials, 2) == 0 && *texture)
		ft_print_error("Error\nDouble texture\n", game);
	return (EXIT_FAILURE);
}

int ft_forward_in_color(char *line, int i, t_game *game)
{
	while (ft_strchr(" \t\v\f\r\n", line[i]))
		i++;
	while (ft_strchr("0123456789", line[i]))
		i++;
	while (ft_strchr(" \t\v\f\r\n", line[i]))
		i++;
	if(line[i] != ',')
		ft_print_error("Error\n1Unreadable color\n", game);
	i++;
	return (i);
}

int	ft_is_a_color(char *line, char *initials, unsigned int *color, t_game *game)
{
	int				i;
	char			**colors;
	int				r;
	int				g;
	int				b;

	i = 1;
	if (ft_strncmp(line, initials, 1) == 0 && *color < 0xFF)
	{
		if (!ft_strchr(" \t\v\f\r\n", line[i]))
			ft_print_error("Error\nUnreadable color\n", game);
		while (ft_strchr(" \t\v\f\r\n", line[i]))
			i++;
		r = ft_atoi_strict(line + i);
		i = ft_forward_in_color(line, i, game);
		g = ft_atoi_strict(line + i);
		i = ft_forward_in_color(line, i, game);
		b = ft_atoi_strict(line + i);
		// i = ft_forward_in_color(line, i, game);
		*color = r + g * 256 + b * 256 * 256 + 0xFF000000;
		return (EXIT_SUCCESS + l_free_tab(colors));
	}
	else if (ft_strncmp(line, initials, 1) == 0 && *color >= 0xFF)
		ft_print_error("Error\nDouble color\n", game);
	return (EXIT_FAILURE);
}

int	ft_get_textures(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (ft_strchr(" \t\v\f\r\n", line[i]))
		i++;
	if (!line[i])
		return (EXIT_FAILURE);
	if (ft_is_a_texture(line + i, "NO", &game->graph->north, game) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_texture(line + i, "SO", &game->graph->south, game) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_texture(line + i, "WE", &game->graph->west, game) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_texture(line + i, "EA", &game->graph->east, game) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_color(line + i, "F", &game->graph->floor, game) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_color(line + i, "C", &game->graph->ceiling, game) == 0)
		return (EXIT_SUCCESS);
	ft_print_error("Error\nUnexpected element\n", game);
	return (EXIT_FAILURE);
}
