/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:10:56 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/17 20:29:48 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_atoi(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	res;
	int				sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		if ((res > 2147483648 && sign == -1) || (res > 2147483647 && sign == 1))
			ft_exit_atoi();
		i++;
	}
	if ((res == 0 && str[i] != 0) || str[i] != '\0')
		ft_exit_atoi();
	return (res * sign);
}
