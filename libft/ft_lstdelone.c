/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:51:13 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/17 15:06:35 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_stack *lst, void (*del)(int))
{
	if (lst && del)
	{
		del(lst->index);
		del(lst->nb);
		del(lst->order_in_stack);
		lst->previous = NULL;
		free(lst);
	}
}
