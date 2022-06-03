/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:04:18 by kmammeri          #+#    #+#             */
/*   Updated: 2021/11/09 15:10:53 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	unsigned const char	*p1;
	unsigned const char	*p2;
	size_t				i;

	p1 = pointer1;
	p2 = pointer2;
	i = 0;
	while (i < size && p1[i] == p2[i])
		i++;
	if (i == size)
		return (0);
	return (p1[i] - p2[i]);
}
