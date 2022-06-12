/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:34:45 by lpuchol           #+#    #+#             */
/*   Updated: 2022/06/12 12:39:44 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	l_free_tab(char **tab)
{
	int	i;

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
		ft_print_error("ft_xmalloc error\n", NULL);
	return (address);
}

char	*l_add_char(char *str, char c)
{
	char	*str_out;
	int		i;

	if (!str && !c)
		return (NULL);
	if (!str)
	{
		str_out = ft_xmalloc(sizeof(char) * 2);
		str_out[0] = c;
		str_out[1] = '\0';
		return (str_out);
	}
	str_out = ft_xmalloc((ft_strlen(str) + 2) * sizeof(char));
	i = -1;
	while (str[++i])
		str_out[i] = str[i];
	str_out[i] = c;
	str_out[i + 1] = '\0';
	free(str);
	return (str_out);
}
