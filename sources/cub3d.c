/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:59:14 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/11 04:44:10 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exit_game(t_game *game)
{
	ft_free_game(game);
	exit(EXIT_SUCCESS);
}

void	ft_print_error(char *err, t_game *game)
{
	(void)game;
	ft_putstr_fd(err, 2);
	ft_free_game(game);
	exit(EXIT_FAILURE);
}

void	ft_check_sprites(t_game *game)
{
	int	fd;

	fd = open(game->graph->north, O_RDONLY);
	if (fd == -1)
		ft_print_error("Error\nSprites North inaccessible\n", game);
	close(fd);
	fd = open(game->graph->south, O_RDONLY);
	if (fd == -1)
		ft_print_error("Error\nSprites South inaccessible\n", game);
	close(fd);
	fd = open(game->graph->east, O_RDONLY);
	if (fd == -1)
		ft_print_error("Error\nSprites East inaccessible\n", game);
	close(fd);
	fd = open(game->graph->west, O_RDONLY);
	if (fd == -1)
		ft_print_error("Error\nSprites West inaccessible\n", game);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_xmalloc(sizeof(t_game));
	ft_init_game(game);
	ft_parsing(argc, argv, game);
	ft_check_sprites(game);
	ft_init_mlx(game);
	ft_free_game(game);
}
