/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:29:36 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/07 20:24:57 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = lst;
	if (!temp)
		return (0);
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
