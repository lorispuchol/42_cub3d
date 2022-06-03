/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:17:54 by kmammeri          #+#    #+#             */
/*   Updated: 2021/11/06 18:27:39 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*str;

	str = malloc(elementSize * elementCount);
	if (!str)
		return (NULL);
	str = ft_memset(str, 0, elementCount * elementSize);
	return (str);
}
