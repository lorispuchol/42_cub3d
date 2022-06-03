/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:18:45 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/12 16:12:04 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		new->next = NULL;
		new->previous = NULL;
		return ;
	}
	tmp = *alst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->next = NULL;
	new->previous = tmp;
	return ;
}
