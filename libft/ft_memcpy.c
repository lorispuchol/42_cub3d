/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:40:44 by kmammeri          #+#    #+#             */
/*   Updated: 2021/11/08 11:31:47 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t size)
{
	size_t		i;
	char		*dst;
	const char	*src;

	dst = dest;
	src = source;
	i = 0;
	if (dest == NULL && source == NULL)
		return (dest);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dest);
}
