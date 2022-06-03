/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:50:20 by kmammeri          #+#    #+#             */
/*   Updated: 2021/11/09 15:11:48 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove( void *dest, const void *source, size_t size)
{
	size_t		i;
	char		*dst;
	const char	*src;

	dst = dest;
	src = source;
	i = 0;
	if (!dst && !src)
		return (0);
	if (source < dest)
		while (size--)
			dst[size] = src[size];
	else
	{
		while (i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dest);
}
