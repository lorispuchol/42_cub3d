/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:53:31 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/09 14:43:44 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_file_map(int argc, char **argv)
{
	int	lenargv;

	if (argc != 2)
		exit(0);
	lenargv = ft_strlen(argv[1]);
	if (argv[1][lenargv - 4] != '.' || argv[1][lenargv - 3] != 'c'
			|| argv[1][lenargv - 2] != 'u' || argv[1][lenargv - 1] != 'b')
		ft_print_error("Error\nThe map is not a '.cub' file\n");
}

int ft_assign_sprites(char *str)
{
	(void) str;
	return (0);
}

/*
int ft_get_header(int fd)
{
	int		i;
	char	*str;
	
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		return (0);
	}
}
*/

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

void	ft_get_data(int fd, t_game *game)
{
	int		index;
	char	*line;

	index = 0;
	line = get_next_line(fd);
	while (line)
	{
		while (index < 6 && line)
		{
			ft_get_textures(line, game);
			free(line);
			line = get_next_line(fd);
			index++;
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	check_valid_map(char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error\nImpossible to open file\n");
	ft_get_data(fd, game);
	// ft_get_header(fd);
}

void	ft_parsing(int argc, char **argv, t_game *game)
{
	check_file_map(argc, argv);
	check_valid_map(argv[1], game);
}
