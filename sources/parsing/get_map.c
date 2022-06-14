/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:11:52 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/14 17:33:26 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_add_line(t_game *game, char *line)
{
	int		i;
	char	**map_new;

	if (!game->map)
	{
		game->map = ft_xmalloc(sizeof(char *) * 2);
		game->map[0] = ft_strtrim(line, "\n");
		free(line);
		game->map[1] = NULL;
		return ;
	}
	i = 0;
	while (game->map[i])
		i++;
	map_new = ft_xmalloc(sizeof(char *) * (i + 2));
	i = -1;
	while (game->map[++i])
		map_new[i] = game->map[i];
	map_new[i] = ft_strtrim(line, "\n");
	free(line);
	map_new[i + 1] = NULL;
	free(game->map);
	game->map = map_new;
}

void	ft_get_map(char *line, int fd, t_game *game)
{
	while (line)
	{
		ft_add_line(game, line);
		line = get_next_line(fd);
	}
}
