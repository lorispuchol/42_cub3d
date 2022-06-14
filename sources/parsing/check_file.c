/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:53:31 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/14 19:34:59 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_file_map(int argc, char **argv, t_game *game)
{
	int	lenargv;

	if (argc < 2)
		ft_print_error("Error\nMissing map file\n", game);
	if (argc > 2)
		ft_print_error("Error\nToo many parametres\n", game);
	lenargv = ft_strlen(argv[1]);
	if (argv[1][lenargv - 4] != '.' || argv[1][lenargv - 3] != 'c'
			|| argv[1][lenargv - 2] != 'u' || argv[1][lenargv - 1] != 'b')
		ft_print_error("Error\nThe map is not a '.cub' file\n", game);
}

int	empty_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '\t'
			&& line[i] != '\v'
			&& line[i] != '\f'
			&& line[i] != '\r'
			&& line[i] != ' '
			&& line[i] != '\n')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_get_data(int fd, t_game *game)
{
	int		index;
	char	*line;

	index = 0;
	line = get_next_line(fd);
	while (index < 6 && line)
	{
		if (empty_line(line) == EXIT_FAILURE)
		{
			ft_get_textures(line, game);
			index++;
		}
		free(line);
		line = get_next_line(fd);
	}
	while (empty_line(line) == EXIT_SUCCESS)
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_get_map(line, fd, game);
	ft_square_map(game);
	ft_check_map(game);
	l_non_null_value(game);
}

void	check_valid_map(char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error\nImpossible to open file\n", game);
	ft_get_data(fd, game);
}

void	ft_parsing(int argc, char **argv, t_game *game)
{
	check_file_map(argc, argv, game);
	check_valid_map(argv[1], game);
}
