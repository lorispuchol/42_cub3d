/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:53:31 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/07 19:49:58 by lpuchol          ###   ########.fr       */
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

void	check_valid_map(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_print_error("Error\nImpossible to open file\n");
	// ft_get_header(fd);
}

void	ft_parsing(int argc, char **argv)
{
	check_file_map(argc, argv);
	check_valid_map(argv[1]);
}
