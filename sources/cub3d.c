/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:59:14 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/09 17:47:27 by lpuchol          ###   ########.fr       */
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
	t_game	*game;

	game = ft_xmalloc(sizeof(t_game));
	ft_init_game(game);
	ft_parsing(argc, argv, game);
	/*
	dprintf(2, "north : %s\n", game->graph->north);
	dprintf(2, "south : %s\n", game->graph->south);
	dprintf(2, "east : %s\n", game->graph->east);
	dprintf(2, "west : %s\n", game->graph->west);
	dprintf(2, "ceiling : %d\n", game->graph->ceiling);
	dprintf(2, "floor : %d\n", game->graph->floor);
	*/
	ft_free_game(game);
}
