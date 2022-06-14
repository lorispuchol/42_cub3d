/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:59:14 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/14 20:05:31 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_game(t_game *game)
{
	if (game)
	{
		if (game->graph)
		{
			if (game->graph->east)
				free(game->graph->east);
			if (game->graph->north)
				free(game->graph->north);
			if (game->graph->west)
				free(game->graph->west);
			if (game->graph->south)
				free(game->graph->south);
			free(game->graph);
		}
		if (game->player)
		{
			free(game->player);
			game->player = NULL;
		}
		free(game);
		game = NULL;
	}
}

void	ft_print_error(char *err, t_game *game)
{
	(void)game;
	ft_putstr_fd(err, 2);
	ft_free_game(game);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		i;

	game = ft_xmalloc(sizeof(t_game));
	ft_init_game(game);
	ft_parsing(argc, argv, game);
	i = -1;
	while (game->map[++i])
		dprintf(1, "%s\n", game->map[i]);
	dprintf(1, "north : %s\n", game->graph->north);
	dprintf(1, "south : %s\n", game->graph->south);
	dprintf(1, "east : %s\n", game->graph->east);
	dprintf(1, "west : %s\n", game->graph->west);
	dprintf(1, "ceiling : %u\n", game->graph->ceiling);
	dprintf(1, "floor : %u\n", game->graph->floor);
	dprintf(1, "y player == %f\n", game->player->y);
	dprintf(1, "x player == %f\n", game->player->x);
	ft_free_game(game);
}
