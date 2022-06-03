/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:53:31 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/03 19:18:43 by kmammeri         ###   ########.fr       */
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

void	check_valid_map(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error\nImpossible to open file\n");
	
}

void	ft_parsing(int argc, char **argv)
{
	check_file_map(argc, argv);
}
