/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:00:57 by kmammeri          #+#    #+#             */
/*   Updated: 2021/11/08 19:41:26 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_loop(const char *str, const char *to_find, size_t len)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (str[i - j] && (i - j) < len)
	{
		if (!to_find[j])
			return ((char *)&str[i - j]);
		if (str[i] == to_find[j] && to_find[j])
			j++;
		else
		{
			i = i - j;
			if (i + ft_strlen(to_find) > len - 1)
				return (NULL);
			j = 0;
		}
		if (len < 0 && !to_find[j])
			return ((char *)&str[i - j]);
		if (str[i - j + 1])
			i++;
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	if (ft_strlen(str) < ft_strlen(to_find))
		return (NULL);
	if (!to_find[0] || (len == 1 && to_find[0] == str[0]))
		return ((char *)str);
	return (ft_loop(str, to_find, len));
}
