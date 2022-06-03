/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:02:11 by kmammeri          #+#    #+#             */
/*   Updated: 2021/11/11 19:08:02 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]))
	{	
		start++;
		if (end - start == 0)
			return (ft_strdup("\0"));
	}
	while (ft_strrchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
