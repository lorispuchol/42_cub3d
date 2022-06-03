/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:31:14 by kmammeri          #+#    #+#             */
/*   Updated: 2022/01/08 17:43:31 by kmammeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int))
{
	t_stack	*temp;
	t_stack	*map;
	int		i;

	i = 0;
	if (!lst || !f)
		return (NULL);
	map = NULL;
	while (lst)
	{
		temp = ft_lstnew(i, f(lst->index), lst->nb);
		if (!temp)
		{	
			if (map)
				ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, temp);
		lst = lst->next;
	}
	return (map);
}
