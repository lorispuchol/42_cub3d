/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:55:31 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/03 18:39:27 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)chr)
			return ((char *)str + i);
		i++;
	}
	if (str && (str[i] == (char)chr))
		return ((char *)str + i);
	return (NULL);
}

char	*gnl_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	if (str[0] == '\0')
		return (NULL);
	len = gnl_strlen(str) - gnl_strlen(gnl_strchr(str, '\n'));
	line = malloc(len + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_mem(char *str)
{
	int		len;
	int		start;
	char	*memnextline;
	int		i;

	len = gnl_strlen(gnl_strchr(str, '\n'));
	i = 0;
	if (len == 0)
	{
		return (NULL);
	}
	start = gnl_strlen(str) - len;
	memnextline = malloc(len + 1);
	if (!memnextline)
		return (NULL);
	while (i < len)
	{
		memnextline[i] = str[start + 1];
		i++;
		start++;
	}
	memnextline[i] = '\0';
	return (memnextline);
}

char	*gnl_read(int fd, char *mem)
{
	char	*str;
	char	*tmp;
	int		stop;

	stop = 1;
	str = NULL;
	if (mem)
		str = gnl_strjoin(mem, str);
	while (!gnl_strchr(str, '\n') && stop > 0)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		stop = read(fd, tmp, BUFFER_SIZE);
		if (stop == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[stop] = '\0';
		if (stop != 0)
			str = gnl_strjoin(str, tmp);
	}
	if (stop == 0)
		free (tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*str;
	char		*txt;

	txt = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (mem && gnl_strchr(mem, '\n'))
		str = mem;
	else
		str = gnl_read(fd, mem);
	txt = gnl_line(str);
	mem = gnl_mem(str);
	if (str)
		free(str);
	return (txt);
}
