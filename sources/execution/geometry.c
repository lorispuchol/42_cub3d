/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:10 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/16 20:24:37 by kmammeri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_vertical_line(t_data *img, t_2dpoint top, t_2dpoint bot, int color)
{
	while (top.y <= bot.y && top.y <= img->height)
	{
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
	while (rect.tl.x <= rect.br.x && rect.tl.x <= img->width)
	{
		ft_vertical_line(img, rect.tl, rect.br, color);
		rect.tl.x++;
	}
}

t_triangle	ft_order_triangle(t_triangle trgl)
{
	t_2dpoint	tmp;

	tmp.x = trgl.a.x;
	tmp.y = trgl.a.y;
	if (trgl.a.x > trgl.b.x)
	{
		trgl.a = trgl.b;
		trgl.b = tmp;
	}
	tmp.x = trgl.a.x;
	tmp.y = trgl.a.y;
	if (trgl.a.x > trgl.c.x)
	{
		trgl.a = trgl.c;
		trgl.c = tmp;
	}
	tmp.x = trgl.b.x;
	tmp.y = trgl.b.y;
	if (trgl.b.x > trgl.c.x)
	{
		trgl.b = trgl.c;
		trgl.c = tmp;
	}
	return (trgl);
}

void	ft_triangle(t_data *img, t_triangle trgl, int color)
{
	float		coef_dir_top;
	float		coef_dir_bot;
	int			x[2];
	int			b[2];
	t_rectangle	line;

	trgl = ft_order_triangle(trgl);
	b[0] = trgl.a.y;
	b[1] = trgl.a.y;
	line.tl = trgl.a;
	line.br = trgl.a;
	x[0] = 1;
	x[1] = 1;
	dprintf(2, "Ax = %d  Ay = %d\n", trgl.a.x, trgl.a.y);
	dprintf(2, "Bx = %d  By = %d\n", trgl.b.x, trgl.b.y);
	dprintf(2, "Cx = %d  Cy = %d\n", trgl.c.x, trgl.c.y);
	if (trgl.a.x == trgl.b.x)
	{
		line.br = trgl.b;
		coef_dir_bot = (float)((float)(trgl.c.y - trgl.a.y) / (float)(trgl.c.x - trgl.a.x));
		coef_dir_top = (float)((float)(trgl.c.y - trgl.b.y) / (float)(trgl.c.x - trgl.b.x));
	}
	else
	{
		coef_dir_bot = (float)((float)(trgl.c.y - trgl.a.y) / (float)(trgl.c.x - trgl.a.x));
		coef_dir_top = (float)((float)(trgl.b.y - trgl.a.y) / (float)(trgl.b.x - trgl.a.x));
	}
	dprintf(2, "coef dir top = %f\n", coef_dir_top);
	dprintf(2, "coef dir bot = %f\n", coef_dir_bot);
	while (trgl.a.x <= trgl.c.x && trgl.a.x <= img->width)
	{
		ft_rectangle(img, line, color);
		if (trgl.a.x == trgl.b.x)
		{
			dprintf(2, "coef dir top = %f\n", coef_dir_top);
			coef_dir_top = (float)((float)(trgl.c.y - trgl.b.y) / (float)(trgl.c.x - trgl.b.x));
			dprintf(2, "coef dir top = %f\n", coef_dir_top);
			b[0] = trgl.b.y;
			x[0] = 1;
		}
		line.tl.x++;
		line.tl.y = x[0] * coef_dir_top + b[0];
		dprintf(2, "top y = %d top x = %d\n", line.tl.y, line.tl.x);
		line.br.x++;
		line.br.y = x[1] * coef_dir_bot + b[1];
		dprintf(2, "bot y = %d bot x = %d\n", line.br.y, line.br.x);
		trgl.a.x++;
		x[0]++;
		x[1]++;
	}
}