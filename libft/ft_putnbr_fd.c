/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:54:53 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/06 21:24:55 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(int j, unsigned int nb)
{
	char	chiffre;
	int		pwr10;

	pwr10 = 1;
	while (j >= 1)
	{
		pwr10 = pwr10 * 10;
		j = j - 1;
	}
	chiffre = (nb / pwr10) + '0';
	write(1, &chiffre, 1);
	while (pwr10 >= 10)
	{
		pwr10 = pwr10 / 10;
		chiffre = (nb / pwr10) % 10 + '0';
		write(1, &chiffre, 1);
	}
}

void	ft_putnbr_fd(int n)
{
	int				i;
	unsigned int	nb2;

	if (n < 0)
	{
		write(1, "-", 1);
		nb2 = -n;
	}
	else
		nb2 = n;
	i = 0;
	while (nb2 >= 10)
	{
		nb2 = nb2 / 10;
		i++;
	}
	ft_print(i, nb2);
}
