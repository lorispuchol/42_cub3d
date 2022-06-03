/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:17:15 by kmammeri          #+#    #+#             */
/*   Updated: 2021/11/08 14:54:45 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int		i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)chr)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
