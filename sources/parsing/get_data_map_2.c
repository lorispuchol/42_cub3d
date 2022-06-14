/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:43:59 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/14 19:50:45 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_forward_in_color(char *line, int i, t_game *game)
{
	while (ft_strchr(" \t\v\f\r\n", line[i]))
		i++;
	while (ft_strchr("0123456789", line[i]))
		i++;
	while (ft_strchr(" \t\v\f\r\n", line[i]))
		i++;
	if (line[i] != ',')
		ft_print_error("Error\nUnreadable color\n", game);
	i++;
	while (ft_strchr(" \t\v\f\r\n", line[i]))
		i++;
	if (!ft_strchr("0123456789", line[i]))
		ft_print_error("Error\nUnreadable color\n", game);
	return (i);
}

void	ft_forward_in_color_2(char *line, int i, t_game *game)
{
	while (ft_strchr("0123456789", line[i]))
		i++;
	while (ft_strchr(" \t\v\f\r", line[i]))
		i++;
	if (line[i] != '\n')
		ft_print_error("Error\nUnreadable color\n", game);
}
