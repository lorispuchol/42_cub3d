/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:50:03 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/09 14:53:41 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_a_texture(char *line, char *initials, char *texture)
{
	int	i;

	i = 2;
	if (ft_strncmp(line, initials, 2) == 0 && !texture)
	{
		while (ft_strchr(" \t\v\f\r\n", line[i]))
			i++;
		while (!ft_strchr(" \t\v\f\r\n", line[i]))
		{
			texture = l_add_char(texture, line[i]);
			i++;
		}
		while (ft_strchr(" \t\v\f\r\n", line[i]))
			i++;
		if (line[i] || !texture)
			ft_print_error("Error\n Unreadable texture in the '.cub' file\n");
		return (0);
	}
	else if (ft_strncmp(line, initials, 2) == 0 && texture)
		ft_print_error("Error\n Double textures in the '.cub' file\n");
	return (1);
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
	return (0);
}

void	ft_get_textures(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (ft_strchr(" \t\v\f\r\n", line[i]))
		i++;
	if (ft_is_a_texture(line + i, "NO", game->graph->north) == 0)
		return ;
	if (ft_is_a_texture(line + i, "SO", game->graph->south) == 0)
		return ;
	if (ft_is_a_texture(line + i, "WE", game->graph->south) == 0)
		return ;
	if (ft_is_a_texture(line + i, "EA", game->graph->south) == 0)
		return ;
	if (ft_is_a_color(line + i, "F", &game->graph->floor) == 0)
		return ;
	if (ft_is_a_color(line + i, "C", &game->graph->ceiling) == 0)
		return ;
	ft_print_error("Error\n Unexpected element in the '.cub' file\n");
}
