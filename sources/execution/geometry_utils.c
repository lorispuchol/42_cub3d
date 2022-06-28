/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:20:57 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/28 20:23:01 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void
	ft_increment_triangle(t_rectangle *l, int *x0, int *x1, t_triangle *t)
{
		l->tl.x++;
		l->br.x++;
		t->a.x++;
		*x0 += 1;
		*x1 += 1;
}

void
	ft_innit_triangle(t_rectangle *l, t_triangle *t, int *b0, int *b1)
{
	*b0 = t->a.y;
	*b1 = t->a.y;
	l->tl = t->a;
	l->br = t->a;
}
