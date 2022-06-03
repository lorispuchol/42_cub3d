/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:59:14 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/03 19:12:42 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	ft_parsing(argc, argv);
}
