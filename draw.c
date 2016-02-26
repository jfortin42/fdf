/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:33:10 by jfortin           #+#    #+#             */
/*   Updated: 2016/02/26 17:40:23 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int	*tmp;

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = e->color;
}

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
		ft_put_pixel(e, e->tmpx, e->tmpy, e->color);
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

void	ft_put_help(t_env e)
{
	int	m_y;

	m_y = 0;
	mlx_string_put(e.mlx, e.win, 0, m_y, 0xFFFFFF, CONTROLS);
	mlx_string_put(e.mlx, e.win, 0, m_y + 16, 0xFFFFFF, H_UP);
	mlx_string_put(e.mlx, e.win, 0, m_y + 32, 0xFFFFFF, H_DOWN);
	mlx_string_put(e.mlx, e.win, 0, m_y + 48, 0xFFFFFF, H_LEFT);
	mlx_string_put(e.mlx, e.win, 0, m_y + 64, 0xFFFFFF, H_RIGHT);
	mlx_string_put(e.mlx, e.win, 0, m_y + 80, 0xFFFFFF, H_PLUS);
	mlx_string_put(e.mlx, e.win, 0, m_y + 96, 0xFFFFFF, H_MINUS);
	mlx_string_put(e.mlx, e.win, 0, m_y + 112, 0xFFFFFF, H_STAR);
	mlx_string_put(e.mlx, e.win, 0, m_y + 128, 0xFFFFFF, H_SLASH);
	mlx_string_put(e.mlx, e.win, 0, m_y + 144, 0xFFFFFF, H_PAGE_UP);
	mlx_string_put(e.mlx, e.win, 0, m_y + 160, 0xFFFFFF, H_PAGE_DOWN);
	mlx_string_put(e.mlx, e.win, 0, m_y + 176, 0xFFFFFF, H_ZERO);
	mlx_string_put(e.mlx, e.win, 0, m_y + 192, 0xFFFFFF, H_ESC);
}
