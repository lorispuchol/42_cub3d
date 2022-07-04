/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorispuchol <lorispuchol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:37:21 by kmammeri          #+#    #+#             */
/*   Updated: 2022/07/04 03:27:13 by lorispuchol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_loop(char *str, char const *s, unsigned int len, \
unsigned int start)
{
	unsigned int	i;

	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;

	if (!s || start >= ft_strlen(s))
	{
		str = ft_strdup("\0");
		return (str);
	}
	if (len < ft_strlen(s))
	{
		str = malloc(len + 1);
		if (!str)
			return (NULL);
	}
	else
	{
		str = malloc(ft_strlen(s) + 1);
		if (!str)
			return (NULL);
	}
	return (ft_loop(str, s, len, start));
}
