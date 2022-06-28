/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmammeri <kmammeri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:10 by kmammeri          #+#    #+#             */
/*   Updated: 2022/06/28 20:21:28 by kmammeri         ###   ########lyon.fr   */
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

void
	ft_cnd_same_line(t_triangle *trgl, t_rectangle *line,
		float *coef_dir_bot, float *coef_dir_top)
{
	if (trgl->a.x == trgl->b.x)
	{
		line->br = trgl->b;
		*coef_dir_bot = (float)((float)(trgl->c.y - trgl->a.y)
				/ (float)(trgl->c.x - trgl->a.x));
		*coef_dir_top = (float)((float)(trgl->c.y - trgl->b.y)
				/ (float)(trgl->c.x - trgl->b.x));
	}
	else
	{
		*coef_dir_bot = (float)((float)(trgl->c.y - trgl->a.y)
				/ (float)(trgl->c.x - trgl->a.x));
		*coef_dir_top = (float)((float)(trgl->b.y - trgl->a.y)
				/ (float)(trgl->b.x - trgl->a.x));
	}
}

void	ft_put_triangle(t_data *img, t_triangle trgl, int color)
{
	float		coef_dir_top;
	float		coef_dir_bot;
	int			x[2];
	int			b[2];
	t_rectangle	line;

	trgl = ft_order_triangle(trgl);
	ft_innit_triangle(&line, &trgl, &b[0], &b[1]);
	x[0] = 1;
	x[1] = 1;
	ft_cnd_same_line(&trgl, &line, &coef_dir_bot, &coef_dir_top);
	while (trgl.a.x <= trgl.c.x && trgl.a.x <= img->width)
	{
		ft_rectangle(img, line, color);
		if (trgl.a.x == trgl.b.x)
		{
			coef_dir_top = (float)((float)(trgl.c.y - trgl.b.y)
					/ (float)(trgl.c.x - trgl.b.x));
			b[0] = trgl.b.y;
			x[0] = 1;
		}
		line.tl.y = x[0] * coef_dir_top + b[0];
		line.br.y = x[1] * coef_dir_bot + b[1];
		ft_increment_triangle(&line, &x[0], &x[1], &trgl);
	}
}
