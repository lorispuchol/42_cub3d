/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:55:51 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/03 18:37:38 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*gnl_calloc(size_t elementCount, size_t elementSize)
{
	char	*str;
	int		i;
	int		count;

	count = elementCount * elementSize;
	str = malloc(count);
	if (!str)
		return (NULL);
	i = 0;
	while (count-- > 0)
		str[i++] = 0;
	return (str);
}

char	*gnl_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = gnl_strlen(src);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	if (src)
		free((char *)src);
	return (str);
}

size_t	gnl_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendest;
	size_t	lensrc;

	j = 0;
	lendest = gnl_strlen(dest);
	i = lendest;
	lensrc = gnl_strlen(src);
	if (size == 0 || size < i)
	{	
		if (src)
			free((char *)src);
		return (size + lensrc);
	}
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (src)
		free((char *)src);
	dest[i] = '\0';
	return (lendest + lensrc);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int			len;
	char		*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	if (!s2)
		return (gnl_strdup(s1));
	len = gnl_strlen(s1) + gnl_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	gnl_strlcat((char *)str, (char *)s1, gnl_strlen(s1) + 2);
	gnl_strlcat((char *)str, (char *)s2, len + 2);
	return (str);
}
