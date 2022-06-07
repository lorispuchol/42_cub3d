/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:34:45 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/07 17:58:40 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void l_free_tab(char **tab)
{
	int i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	*ft_xmalloc(size_t size)
{
	void	*address;

	address = malloc(size);
	if (!address)
		ft_print_error("malloc error\n");
	return (address);
}