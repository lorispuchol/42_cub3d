/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:44:00 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/12 16:26:17 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack *alst, t_stack *new)
{
	if (new && alst)
	{
		alst->previous = new;
		new->next = alst;
		new->previous = NULL;
		alst = new;
	}
}
