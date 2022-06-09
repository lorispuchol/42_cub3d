/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:50:03 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/09 18:26:33 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	l_non_null_value(t_game *game)
{
	dprintf(2, "north : %s\n", game->graph->north);
	dprintf(2, "south : %s\n", game->graph->south);
	dprintf(2, "east : %s\n", game->graph->east);
	dprintf(2, "west : %s\n", game->graph->west);
	dprintf(2, "ceiling : %d\n", game->graph->ceiling);
	dprintf(2, "floor : %d\n", game->graph->floor);
	if(!game->graph->north
		|| !game->graph->south	
		|| !game->graph->east	
		|| !game->graph->west	
		|| game->graph->ceiling	== -1
		|| game->graph->floor == -1)
		ft_print_error("Error\nMissing texture element\n");	
}


int	ft_is_a_texture(char *line, char *initials, char **texture)
{
	int	i;

	i = 2;
	if (ft_strncmp(line, initials, 2) == 0 && !*texture)
	{
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
			ft_print_error("Error\nUnreadable texture in the '.cub' file\n");
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(line, initials, 2) == 0 && *texture)
		ft_print_error("Error\nDouble textures in the '.cub' file\n");
	return (EXIT_FAILURE);
}

int	ft_is_a_color(char *line, char *initials, int *color)
{
	int	i;

	i = 1;
	if (ft_strncmp(line, initials, 1) == 0 && *color == -1)
	{
		while (ft_strchr(" \t\v\f\r\n", line[i]))
			i++;
		// je me suis arreté ici , check des couleurs
	}
	return (1);
}

int	ft_get_textures(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (ft_strchr(" \t\v\f\r\n", line[i]))
		i++;
	if (!line[i])
		return (EXIT_FAILURE);
	if (ft_is_a_texture(line + i, "NO", &game->graph->north) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_texture(line + i, "SO", &game->graph->south) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_texture(line + i, "WE", &game->graph->west) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_texture(line + i, "EA", &game->graph->east) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_color(line + i, "F", &game->graph->floor) == 0)
		return (EXIT_SUCCESS);
	if (ft_is_a_color(line + i, "C", &game->graph->ceiling) == 0)
		return (EXIT_SUCCESS);
	ft_print_error("Error\nUnexpected element in the '.cub' file\n");
	return (EXIT_FAILURE);
}
