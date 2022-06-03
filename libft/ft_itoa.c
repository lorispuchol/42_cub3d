/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:36:41 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/06 21:22:27 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenint(unsigned int i)
{
	size_t	len;

	len = 0;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

static char	*ft_strint(unsigned int n, size_t len, int sign)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (sign == -1)
		str[len] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;
	size_t	len;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		sign = -1;
		n = -n;
		len = 1;
	}
	len = len + ft_lenint(n);
	str = ft_strint(n, len, sign);
	return (str);
}
