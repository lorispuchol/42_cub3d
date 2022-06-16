/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpuchol <lpuchol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:10 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/16 13:21:24 by lpuchol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_vertical_line(t_data *img, t_2dpoint top, t_2dpoint bot, int color)
{
	dprintf(2, "top.y == %d  img.height == %d\n", top.y, img->height);
	while (top.y <= bot.y && top.y <= img->height)
	{
		dprintf(2, "line == %d\n", top.y);
		ft_set_pix(img, top.x, top.y, color);
		top.y++;
	}
}

void	ft_rectangle(t_data *img, t_rectangle rect, int color)
{
	t_2dpoint	tmp;

	tmp.x = rect.tl.x;
	tmp.y = rect.tl.y;
	if (rect.tl.y > rect.br.y)
	{
		rect.tl.y = rect.br.y;
		rect.br.y = tmp.y;
	}
	if (rect.tl.x > rect.br.x)
	{
		rect.tl.x = rect.br.x;
		rect.br.x = tmp.x;
	}
	dprintf(2, "tl :  x = %d  y = %d\n", rect.tl.x, rect.tl.y);
	dprintf(2, "br :  x = %d  y = %d\n", rect.br.x, rect.br.y);
	while (rect.tl.x <= rect.br.x && rect.tl.x <= img->width)
	{
		dprintf(2, "column == %d\n", rect.tl.x);
		ft_vertical_line(img, rect.tl, rect.br, color);
		rect.tl.x++;
	}
}

// void	ft_triangle(t_data *img, t_triangle trgl, int color)
// {
// }