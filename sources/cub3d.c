/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:59:14 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/09 00:00:10 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_game(t_game *game)
{
	(void) game;
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_init_game(&game);
	ft_parsing(argc, argv, &game);
	ft_free_game(&game);
}
