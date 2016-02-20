/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:33:10 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/20 17:49:21 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(int x2, int y2, t_env *e)
{
	e->tmpx = e->x_prim;
	e->tmpy = e->y_prim;
	e->dx = abs(x2 - e->x_prim);
	e->dy = abs(y2 - e->y_prim);
	e->sx = e->x_prim < x2 ? 1 : -1;
	e->sy = e->y_prim < y2 ? 1 : -1;
	e->error = (e->dx > e->dy ? e->dx : -(e->dy)) / 2;
	while (!(e->tmpy == y2 && e->tmpx == x2))
	{
		mlx_pixel_put(e->mlx, e->win, e->tmpx, e->tmpy, e->color);
		e->tmp_error = e->error;
		if (e->tmp_error > -(e->dx))
		{
			e->error -= (e->dy);
			e->tmpx += e->sx;
		}
		if (e->tmp_error < (e->dy))
		{
			e->error += (e->dx);
			e->tmpy += e->sy;
		}
	}
}
