/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:46:49 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/09 22:10:02 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *str, char *sep)
{
	int	i;
	int	countword;

	i = 0;
	if (!sep)
		return (1);
	countword = 0;
	while (str[i])
	{
		while (ft_strchr(sep, str[i]) && str[i])
		{
			i++;
		}
		while (!ft_strchr(sep, str[i]) && str[i])
		{
			i++;
		}
		if (!ft_strchr(sep, str[i - 1]))
			countword++;
		while (ft_strchr(sep, str[i]) && str[i])
		{
			i++;
		}
	}
	return (countword);
}

static int	ft_countchar(char const *str, char *sep, int startwd)
{
	int	lenword;

	lenword = 0;
	if (!sep)
	{
		while (str[startwd + lenword])
			lenword++;
		return (lenword);
	}
	while (!ft_strchr(sep, str[startwd + lenword]) && str[startwd + lenword])
		lenword++;
	return (lenword);
}

static int	ft_startword(char const *str, char *sep, int nbword)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!sep)
		return (0);
	while (str[i])
	{
		while (ft_strchr(sep, str[i]) && str[i])
			i++;
		word++;
		if (word == nbword + 1)
			return (i);
		while (!ft_strchr(sep, str[i]) && str[i])
			i++;
		while (ft_strchr(sep, str[i]) && str[i])
			i++;
	}
	return (0);
}

static void	ft_freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split_with_str(char const *s, char *sep)
{
	char	**strsplit;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strsplit = malloc(sizeof(char *) * (ft_countword(s, sep) + 1));
	if (!strsplit)
		return (NULL);
	while (i < ft_countword(s, sep))
	{
		strsplit[i] = ft_substr(s, ft_startword(s, sep, i), \
		ft_countchar(s, sep, ft_startword(s, sep, i)));
		if (!strsplit[i])
			ft_freeall(strsplit);
		i++;
	}
	strsplit[i] = 0;
	return (strsplit);
}
