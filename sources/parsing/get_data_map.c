/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:50:03 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/12 13:23:28 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	l_non_null_value(t_game *game)
{
	dprintf(2, "north : %s\n", game->graph->north);
	dprintf(2, "south : %s\n", game->graph->south);
	dprintf(2, "east : %s\n", game->graph->east);
	dprintf(2, "west : %s\n", game->graph->west);
	dprintf(2, "ceiling : %u\n", game->graph->ceiling);
	dprintf(2, "floor : %u\n", game->graph->floor);
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
		if (!ft_strchr(" \t\v\f\r\n", line[i]))
			ft_print_error("Error\nUnreadable texture\n", game);
		while (ft_strchr(" \t\v\f\r\n", line[i]))
			i++;
		while (!ft_strchr(" \t\v\f\r\n", line[i]))
		{
			*texture = l_add_char(*texture, line[i]);
			i++;
		}
		while (ft_strchr(" \t\v\f\r\n", line[i]))
			i++;
		if (line[i] && !*texture)
			ft_print_error("Error\nUnreadable texture\n", game);
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(line, initials, 2) == 0 && *texture)
		ft_print_error("Error\nDouble texture\n", game);
	return (EXIT_FAILURE);
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
			ft_print_error("Error\nUnreadable texture\n", game);
		while (ft_strchr(" \t\v\f\r\n", line[i]))
			i++;
		colors = ft_split_with_str(line + i, ", \t\v\f\r\n");
		if (!colors || !colors[0] || !colors[1] || !colors[2] || colors[3])
			ft_print_error("Error\nUnreadable color\n", game);
		r = ft_atoi_strict(colors[0]);
		g = ft_atoi_strict(colors[1]);
		b = ft_atoi_strict(colors[2]);
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
